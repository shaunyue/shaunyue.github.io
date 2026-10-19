# 程序设计 I · Fall 2026

课程主页：https://shaunyue.github.io/teaching/cse101/2026-fall/

## 平时更新只需三步

1. 将课件 PDF 放入 `materials/slides/`，将主示例 `.c` 文件放入 `materials/code/`。
2. 在 **materials.json** 中复制一节的配置，修改章节编号、中英文名称、文件名及回放地址。
3. 运行更新命令，刷新本地预览，检查后提交发布。

**资料表只在 materials.json 中维护。不要手动编辑 index.html 的资料行，下一次更新命令会覆盖这些行。**
保存配置本身不会更新网页；需要运行一次下面的命令。配置有错误或所填写的文件不存在时，程序会提示位置或原因，并保留原网页。

## 配置怎么填写

配置最外层是 `[...]`，每节用一个 `{...}` 表示，按文件中的顺序展示。下面是已收录的第7节示例，可复制后修改为下一节：

```json
{
  "number": 7,
  "zh": "数组",
  "en": "Arrays",
  "slides": "lecture07.pdf",
  "code": "chapter07.c",
  "videos": ["https://meeting.tencent.com/ctm/KP6k0Jae97"]
}
```

| 字段 | 如何填写 |
|---|---|
| `number` | 正整数，如 `7`；网页自动显示为 `07`。不要重复编号，也不要写数字 `07`。 |
| `zh` | 中文章节名称。 |
| `en` | 英文章节名称。 |
| `slides` | PDF文件名，不包含路径；没有课件时填 `""` 或省略该字段。 |
| `code` | `.c` 文件名，不包含路径；没有代码时填 `""` 或省略该字段。 |
| `videos` | 按播放顺序填写完整 HTTPS 网址；没有回放时填 `[]` 或省略该字段。 |

追加一节时，记得在上一节的 `}` 后加逗号；最后一节后不加逗号。JSON 不支持注释。文件名的大小写需与实际文件一致。新增章节时请修改编号、名称、文件名和回放网址；相应文件需先放入指定目录。

回放标签自动生成，无需填写中英文标签或辅助说明：

| 回放数量 | 中文标签 | 英文标签 |
|---|---|---|
| 1段 | `[回放]` | `[video]` |
| 2段 | `[上]` `[下]` | `[video 1]` `[video 2]` |
| 3段 | `[上]` `[中]` `[下]` | `[video 1]` `[video 2]` `[video 3]` |
| 4段及以上 | `[回放1]` `[回放2]` … | `[video 1]` `[video 2]` … |

保留腾讯会议提供的完整网址，`/crm/` 和 `/ctm/` 均原样填写，不自行拼接或修改路径。课件标签自动为 `[课件]` / `[slides]`，代码标签自动为 `[代码]` / `[code]`；代码保留下载行为，课件和回放在新标签打开。

## 更新网页与发布

在个人主页仓库根目录执行：

```sh
cd /Users/shawn/Homepage/shaunyue.github.io
python3 teaching/cse101/2026-fall/update_materials.py
```

更新命令仅修改课程资料表，不改变页面其他区块、样式、附件内容或2025课程。它会显示当前章节数和资料链接数。只替换相同文件名的附件时，链接无需修改。

检查配置和网页是否同步（不会写入文件）：

```sh
python3 teaching/cse101/2026-fall/update_materials.py --check
```

本地预览：http://127.0.0.1:4000/teaching/cse101/2026-fall/

如果预览服务没有运行，在另一个终端启动：

```sh
cd /Users/shawn/Homepage/shaunyue.github.io
bundle exec jekyll serve --host 127.0.0.1 --port 4000
```

保存配置并运行更新命令后，已有预览服务会重新生成页面。按 `Control+C` 停止预览服务。

检查通过后发布（包括配置与生成后的 HTML）：

```sh
git add -- teaching/cse101/2026-fall
git commit -m "Update course materials"
git -c credential.helper= -c 'credential.helper=!gh auth git-credential' push https://github.com/shaunyue/shaunyue.github.io.git master
```

GitHub Pages 沿用 `master` 分支根目录发布，不在服务器上运行 Python。每次修改配置后务必先运行更新命令。发布完成后检查线上新资料；若浏览器仍显示旧内容，可用 `Command+Shift+R` 强制刷新。

## 文件与页面说明

- `materials.json`：章节资料的唯一配置来源。
- `update_materials.py`：只使用 Python 3 标准库，校验配置并生成静态资料表。
- `test_update_materials.py`：更新程序的检查，涵盖回放标签、内容转义、错误配置及重复更新。
- `index.html`：已生成的静态网页；课程简介、教学团队、上课安排和参考书目仍在这里编辑。
- `style.css`：既有的白底黑字、蓝色链接、表格及手机布局。
- `language.js`：双语切换、语言偏好记忆与 `?lang=zh` / `?lang=en`。
- `favicon.ico`：课程图标。
- `materials/slides/`、`materials/code/`：原始课件和主示例代码。
- `materials/course/`：两份课程说明文档，仅归档保存。

整个课程文件夹仍可独立复制或直接双击 index.html 查看；更新完成的静态资料表无需 JavaScript 即可阅读中文。没有新增前端框架或第三方依赖。

在课程目录内运行程序检查：

```sh
python3 -B -m unittest test_update_materials.py
```

当前共有7章、26个资料链接，收录第1–7节的课件、主示例代码与回放。第6节使用用户导出的77页 PDF 与原始 chapter06.c；第7节使用原始27页 PDF 与 chapter07.c，回放为 https://meeting.tencent.com/ctm/KP6k0Jae97。课件、代码与课程说明文档保留原内容；回放访问和播放权限由腾讯会议管理。

每次更新后核对新章节中英文、全部链接、下载文件名、回放顺序、手机布局及200%放大；保留课程信息表格的完整上边线。维护后的课程副本和ZIP也应从实际课程目录重新复制和打包。
