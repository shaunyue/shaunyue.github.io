#!/usr/bin/env python3
"""从同目录的 materials.json 更新静态课程资料表，无第三方依赖。"""
import json
from html import escape
from pathlib import Path
import re
import sys
from urllib.parse import quote, urlsplit


def translated(zh, en):
    return f'<span data-en="{escape(en, quote=True)}">{escape(zh)}</span>'


def material_link(href, zh, en, description_zh, description_en, download=False):
    behavior = ' download' if download else ' target="_blank" rel="noopener"'
    return (f'<a href="{escape(href, quote=True)}"{behavior}'
            f' aria-label="{escape(description_zh, quote=True)}"'
            f' data-label-en="{escape(description_en, quote=True)}">'
            f'{translated(zh, en)}</a>')


def render_rows(chapters, folder):
    if not isinstance(chapters, list):
        raise ValueError('配置最外层应为章节数组 [...]。')
    rows, numbers, link_count = [], set(), 0
    for chapter in chapters:
        if not isinstance(chapter, dict):
            raise ValueError('每个章节应为一个对象 {...}。')
        unknown = set(chapter) - {'number', 'zh', 'en', 'slides', 'exercises', 'code', 'videos'}
        if unknown:
            raise ValueError(f'未知字段：{", ".join(sorted(unknown))}。')
        number = chapter.get('number')
        if type(number) is not int or number < 1:
            raise ValueError('number 应为正整数，例如 7；不要写成 07。')
        if number in numbers:
            raise ValueError(f'第{number}节的编号重复。')
        numbers.add(number)
        for language in ['zh', 'en']:
            if not isinstance(chapter.get(language), str) or not chapter[language].strip():
                raise ValueError(f'第{number}节缺少 {language} 章节名称。')
        zh, en = chapter['zh'], chapter['en']
        prefix_zh, prefix_en = f'第{number}节 {zh}：', f'Chapter {number}, {en}: '
        cells = {}
        for field, directory, extension, label_zh, label_en, description_zh, description_en in [
            ('slides', 'slides', '.pdf', '[课件]', '[slides]', '课件 PDF', 'slides PDF'),
            ('exercises', 'slides', '.pdf', '[练习]', '[exercises]', '练习课件 PDF', 'exercise slides PDF'),
            ('code', 'code', '.c', '[代码]', '[code]', '下载代码', 'download code'),
        ]:
            filename = chapter.get(field, '')
            if not isinstance(filename, str):
                raise ValueError(f'第{number}节的 {field} 应为文件名或空字符串。')
            if not filename:
                cells[field] = ''
                continue
            if '/' in filename or '\\' in filename or Path(filename).suffix.lower() != extension:
                raise ValueError(f'第{number}节的 {field} 只填写 {extension} 文件名，不填写路径。')
            relative = f'materials/{directory}/{filename}'
            if not (folder / relative).is_file() or filename not in {p.name for p in (folder / 'materials' / directory).iterdir()}:
                raise ValueError(f'第{number}节文件不存在或文件名大小写不一致：{relative}')
            cells[field] = material_link(f'materials/{directory}/{quote(filename)}', label_zh, label_en,
                                         prefix_zh + description_zh, prefix_en + description_en,
                                         download=field == 'code')
            link_count += 1
        videos = chapter.get('videos', [])
        if not isinstance(videos, list):
            raise ValueError(f'第{number}节的 videos 应为网址数组；没有录像时填写 []。')
        video_links = []
        for index, url in enumerate(videos):
            if not isinstance(url, str) or any(c.isspace() for c in url):
                raise ValueError(f'第{number}节的第{index + 1}段回放应为完整 HTTPS 网址。')
            parsed = urlsplit(url)
            if parsed.scheme != 'https' or not parsed.netloc:
                raise ValueError(f'第{number}节的第{index + 1}段回放应为完整 HTTPS 网址。')
            count = len(videos)
            if count == 1:
                labels = ('[回放]', '[video]', '课堂回放', 'watch recording')
            else:
                part = {2: ['上', '下'], 3: ['上', '中', '下']}.get(count)
                name = part[index] if part else str(index + 1)
                labels = (f'[{name}]' if part else f'[回放{name}]', f'[video {index + 1}]',
                          f'回放{name}', f'recording, part {index + 1} of {count}')
            video_links.append(material_link(url, labels[0], labels[1],
                                             prefix_zh + labels[2], prefix_en + labels[3]))
        link_count += len(video_links)
        slides_class = ' class="slides"' if cells['exercises'] else ''
        rows.append(f'''            <tr>
              <th scope="row"><span class="chapter-number">{number:02d}</span>{translated(zh, en)}</th>
              <td{slides_class}>{cells['slides']}{cells['exercises']}</td>
              <td>{cells['code']}</td>
              <td class="recordings">{''.join(video_links)}</td>
            </tr>''')
    return '\n'.join(rows), link_count


def update(folder, check=False):
    chapters = json.loads((folder / 'materials.json').read_text(encoding='utf-8'))
    rows, links = render_rows(chapters, folder)
    index = folder / 'index.html'
    original = index.read_text(encoding='utf-8')
    generated = '\n            <!-- Generated from materials.json; run python3 update_materials.py. -->\n' + rows + '\n          '
    pattern = r'(<table class="materials-table">.*?<tbody>).*?(</tbody>)'
    updated, matches = re.subn(pattern, lambda m: m[1] + generated + m[2], original, flags=re.S)
    if matches != 1:
        raise ValueError('index.html 中应有且仅有一个 materials-table 资料表。')
    if check:
        if updated != original:
            raise ValueError('配置与网页尚未同步，请先运行 python3 update_materials.py。')
    elif updated != original:
        temporary = index.with_name('.index.html.tmp')
        try:
            temporary.write_text(updated, encoding='utf-8')
            temporary.replace(index)
        finally:
            temporary.unlink(missing_ok=True)
    return len(chapters), links


if __name__ == '__main__':
    if sys.argv[1:] not in ([], ['--check']):
        sys.exit('用法：python3 update_materials.py [--check]')
    try:
        count, links = update(Path(__file__).resolve().parent, check='--check' in sys.argv)
        print(f'资料配置已同步：{count}章，{links}个资料链接。')
    except json.JSONDecodeError as error:
        sys.exit(f'配置格式错误：materials.json 第{error.lineno}行、第{error.colno}列：{error.msg}')
    except (ValueError, OSError) as error:
        sys.exit(f'更新失败：{error}。原网页保持不变。')
