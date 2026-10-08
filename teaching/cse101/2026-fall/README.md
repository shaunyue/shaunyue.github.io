# 程序设计 I · 2026年秋季

公开网址：https://shaunyue.github.io/teaching/cse101/2026-fall/

本文件夹包含完整课程页和全部课程资料。使用静态 HTML、CSS 和 JavaScript，无需安装依赖或构建。双击 `index.html` 即可本地查看，也可将整个文件夹复制到任意静态网站。

## 文件位置

- `index.html`：课程简介、教学团队、上课安排、参考书目、5个章节资料以及中英文文本。
- `style.css`：字体、绿色主题和手机布局。
- `language.js`：语言切换、语言偏好记忆与分享链接。
- `favicon.ico`：个人主页原有图标。
- `materials/slides/lecture01.pdf` 至 `lecture05.pdf`：第1至5节课件。
- `materials/code/chapter01.c` 至 `chapter05.c`：原始示例代码。
- `materials/course/course-introduction.doc`：原始课程简介。
- `materials/course/syllabus.doc`：原始课程教学大纲。

两份课程说明文档仅归档，不在资料页增加入口。课件、代码和文档均与提供的原文件一致。回放保留腾讯会议原链接，访问要求由腾讯会议管理。

## 添加章节

1. 将课件放入 `materials/slides/`，例如 `lecture06.pdf`；将代码放入 `materials/code/`，例如 `chapter06.c`。
2. 在 `index.html` 的 `<table class="materials-table">` 下的 `<tbody>` 中复制一整行 `<tr>…</tr>`，修改章节编号、中文名称和 `data-en` 中的英文名称。注意不要复制教学团队表格的行。
3. 修改课件和代码的 `href`。代码链接保留 `download`；课件和回放保留 `target="_blank" rel="noopener"`。
4. 填入对应回放的完整网址。两段回放使用「上／下」和「Part 1／Part 2」；只有一段时复制第一节的回放单元格。
5. 同时更新各链接的中文 `aria-label` 和英文 `data-label-en`，让屏幕阅读器读出正确章节和资料类型。

还未提供的资料不要使用空地址或 `#` 占位链接，可用普通文字「待更新」。

## 替换已有课件或代码

直接替换相同文件名即可，网页链接无需更改。若更改文件名，需同步修改 `index.html` 中的 `href`。只上传 `.c` 源码，不需要可执行文件、调试文件或编辑器临时文件。

## 修改中英文

`index.html` 中的可见文字是中文，紧邻的 `data-en="…"` 是对应英文。例如：

```html
<span data-en="Expressions">表达式</span>
```

资料链接的辅助说明使用 `aria-label`（中文）和 `data-label-en`（英文）。页面标题位于 `<title>`；搜索描述的中文位于 `<meta name="description">`，英文位于 `language.js`。网页不会翻译附件或录像内容。

首次访问默认中文。有效的 `?lang=zh` 或 `?lang=en` 优先于已保存的语言；未指定语言时使用浏览器保存的偏好。浏览器禁用存储时仍可切换，禁用 JavaScript 时仍可查看完整中文资料页。

## 更新课程信息

页面按「课程名称与学期 → 简介 → 教学团队 → 上课安排 → 参考书目 → 课程资料」排列。英文对应 Course Staff、Lecture、References 和 Course Materials。

- 教学团队位于 `staff-table`，姓名、职务及答疑时间的英文位于 `data-en`。更新邮箱时同时修改链接文字和 `mailto:` 地址。人员时间是 Office Hours，不是上课时间。
- 上课安排位于 `lecture-list`。「第3–4节」对应英文 `Periods 3–4`，不换算为3–4点。周次分别为周一1–17周、周三1–9周。
- 参考书目位于 `references-list`。书籍版本、ISBN和出版日期在两种语言下指向同一版本。C Primer Plus 使用 Stephen Prata 的英文原版第六版，Addison-Wesley Professional，ISBN 9780321928429，出版日期 2013-11-26；来源：https://www.informit.com/store/c-primer-plus-9780321928429 。
- 课程资料表使用 `materials-table`，教学团队使用 `staff-table`。调整行距或手机布局时分别限定这些样式，避免互相影响。

## 发布与检查

本文件夹在个人主页仓库中的位置为 `teaching/cse101/2026-fall/`。仓库沿用现有 GitHub Pages 设置：从 `master` 分支根目录发布。主页 `_pages/homepage.md` 的 Teaching 条目将 Fall 2026 链接到该目录。

每次更新后检查：

1. 中英文的标题、简介、章节和资料标签均正确；切换后刷新仍保持所选语言。
2. 每个 PDF、代码及回放均对应同一章节；课程材料表仍有5章、18个资料链接。分别核对三名团队成员的姓名、邮箱、答疑时间和两条上课安排。
3. 手机和桌面显示完整，200% 放大后没有遮挡。
4. 发布后检查线上文件，而非只检查本地副本；腾讯会议可能要求登录。

## 当前回放对应关系

| 章节 | 回放 |
| --- | --- |
| 1 C语言概述 | `KDap0oxV56` |
| 2 变量常量 | `NLE8aLB6a0` |
| 3 表达式 | 上 `2r6GLok517`；下 `24pe4yDm67` |
| 4 选择结构 | 条件控制上 `NgpQaRR758`；下 `NLEqBQv659` |
| 5 循环结构 | 循环控制上 `l53ORPQZaa`；下 `KmkM3naM6f` |

回放地址前缀为 `https://meeting.tencent.com/crm/`。章节编号以已提供课件为准，与原始大纲中的章节安排分别保留。
