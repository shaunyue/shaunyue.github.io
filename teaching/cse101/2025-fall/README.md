# 程序设计 I · Fall 2025

这是独立的静态课程目录，网页默认中文，可切换英文。它使用个人主页的字体、白底黑字与蓝色链接，不需要前端框架或额外构建依赖。

## 访问与文件组织

- 仓库路径：`teaching/cse101/2025-fall/`
- 线上页面：https://shaunyue.github.io/teaching/cse101/2025-fall/
- 本地课程页：http://127.0.0.1:4000/teaching/cse101/2025-fall/
- 指定语言：在网址末尾使用 `?lang=zh` 或 `?lang=en`。优先采用网址指定语言，其次使用已保存偏好，再默认中文；偏好与 CSE101 其他学期共享。
- `index.html`：课程文字、人员信息、上课安排、参考书目、章节与课件地址。
- `style.css`：当前模板的排版；资料表仅有章节和课件两列，桌面宽度约 80% / 20%。
- `language.js`：语言切换、页面描述及语言记忆。
- `favicon.ico`：与现有课程模板相同的图标。
- `materials/slides/`：14章、15份主课件 PDF，保留原始内容；不包含代码、回放、实验或补充材料。

可直接打开 `index.html`；通过现有本地预览服务访问时，主页入口也可使用。

## 后续维护

1. 在 `index.html` 中修改中文文字及对应的 `data-en` 英文。链接的辅助说明同时修改 `aria-label` 和 `data-label-en`。不要在同一个 `data-en` 元素内放需要保留的子元素。
2. 替换课件时，将新 PDF 放入 `materials/slides/` 并沿用稳定英文文件名；更改名称时同步修改链接。课件链接保留 `target="_blank"` 和 `rel="noopener"`。
3. 追加章节时，复制资料表 `<tbody>` 内的一整行 `<tr>`，更新编号、章节中英文名称、PDF 地址、可见标签及辅助说明。
4. 一份课件使用 `[课件]` / `[slides]`；分上下册使用 `[上]` `[下]` / `[slides 1]` `[slides 2]`。相邻链接间距由 CSS 的 `.materials-table td a + a` 控制。
5. 如更改学期，需同时更新中英文标题、副标题、中文描述、canonical 地址和 `language.js` 的英文描述。参考书版本、日期和课程时间应分别核对中英文。
6. 教学团队中的姓名、角色、答疑时间分别带翻译；邮箱修改时同步修改显示文字与 `mailto:` 地址。教师姓名保留个人主页链接。
7. 主页课程入口在 `_pages/homepage.md` 的 Teaching 段落，使用 Markdown 编辑，课程与说明之间保留行末反斜杠换行。
8. 本地检查后提交到现有 GitHub Pages 的 `master` 分支根目录。发布完成后检查课程页、主页入口和全部15个课件链接。

参考书目不显示编号、ISBN、斜体或链接。第一本采用第五版及出版日期2017-08-01（清华大学出版社书目： https://www.tup.tsinghua.edu.cn/booksCenter/book_07645004.html ）。第二本保留2026课程模板中的文字。

## 课件来源映射

原始目录：`/Users/shawn/个人/中大工作/课程/25程序设计/课件/`。
章节以目录和文件名为准；不修改PDF封面中的原有编号。第9章收录上下册，不重复收录与上册内容相同的 `第9节-字符串.pdf`。

| 本目录文件 | 原始相对路径 |
|---|---|
| lecture01.pdf | 第1节 C语言概述/第1节-C语言概述.pdf |
| lecture02.pdf | 第2节 变量常量/第2节-变量常量.pdf |
| lecture03.pdf | 第3节 运算符表达式/第3节-运算符表达式.pdf |
| lecture04.pdf | 第4节 选择结构/第4节-选择结构.pdf |
| lecture05.pdf | 第5节 循环结构/第5节-循环结构.pdf |
| lecture06.pdf | 第6节 函数/第6节-函数.pdf |
| lecture07.pdf | 第7节 数组/第7节-数组.pdf |
| lecture08.pdf | 第8节 数组与指针/第8节-数组与指针.pdf |
| lecture09-part1.pdf | 第9节 字符串/第9节-字符串（上）.pdf |
| lecture09-part2.pdf | 第9节 字符串/第9节-字符串（下）.pdf |
| lecture10.pdf | 第10节 函数与指针/第10节-函数与指针.pdf |
| lecture11.pdf | 第11节 结构体/第11节-结构体.pdf |
| lecture12.pdf | 第12节 链表/第12节-链表.pdf |
| lecture13.pdf | 第13节 结构体进阶/第13节-结构体进阶.pdf |
| lecture14.pdf | 第14节 文件/第14节-文件.pdf |
