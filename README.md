# Sheng Yue's homepage

This site uses Jekyll. Edit personal information here:

- `_config.yml`: name, navigation title, position, portrait, contact links, and search description. The Sidebar Email link and prospective-student contact link both use `author.email`. Replace `images/avatar.png` to update the portrait.
- `_config.yml`'s `author.name_zh`: the Chinese profile name. `.name-cn` in `assets/css/main.css` uses a bold sans-serif Chinese font coordinated with the English name.
- `_pages/homepage.md`: biography, news, publications, grants, awards, and service. Add or remove entries using Markdown; each publication belongs under Conference Papers, Journal Papers, or Books & Chapters, in reverse chronological order. Keep the publication year in its citation; do not add separate year headings.
- `_data/group.yml`: student names, group category, cohort year, joining date, gender, and optional photo path. Set `gender` to `male` or `female` for the matching default portrait; leave it empty for the neutral portrait. Add a square or rectangular photo under `images/students/` and set `photo` to its site path, such as `/images/students/liang-liu.jpg`. The page crops it automatically.
- `_pages/group.md`: the Group Members page layout and introductory text.
- `_data/navigation.yml`: the five navigation links.

A publication uses three Markdown lines: a title (optionally linked), authors, then an italic venue and date. The first two lines end with two spaces to keep the fields separate. Copy a nearby entry when adding one. Link each conference acronym to that year's official conference homepage, and each journal acronym to its official journal homepage. Keep the `**...**` wrappers around titles and venue acronyms as CSS styling hooks; both display at normal weight. Keep `**Sheng Yue**` in author lines as a CSS styling hook: it displays in bold black, while other authors display in black at normal weight. Use `<sup>\*</sup>` for corresponding authors and `<sup>#</sup>` for co-first authors. News and grants use a date line followed by an indented detail line; copy a nearby entry to keep the layout.

Awards use a plain award name followed by the year. Academic Service lists the plain role before the linked organization or venue. Talks use a plain title, an italic event or conference, then a plain institution/location and date. Keep News in reverse chronological order.

Preview with `bundle exec jekyll serve` at `http://127.0.0.1:4000/`. Local edits are not published until pushed.
