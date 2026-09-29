# Sheng Yue's homepage

This site uses Jekyll. Edit personal information here:

- `_config.yml`: name, navigation title, position, portrait, contact links, and search description. Replace `images/avatar.png` to update the portrait.
- `_pages/homepage.md`: biography, news, publications, grants, awards, and service. Add or remove entries using Markdown; each publication belongs under its type and year.
- `_data/group.yml`: student names, group category, cohort year, joining date, gender, and optional photo path. Set `gender` to `male` or `female` for the matching default portrait; leave it empty for the neutral portrait. Add a square or rectangular photo under `images/students/` and set `photo` to its site path, such as `/images/students/liang-liu.jpg`. The page crops it automatically.
- `_pages/group.md`: the Group Members page layout and introductory text.
- `_data/navigation.yml`: the five navigation links.

A publication uses three Markdown lines: a bold title (optionally linked), authors, then an italic venue and date. The first two lines end with two spaces to keep the fields separate. Copy a nearby entry when adding one. Use `<sup>\*</sup>` for corresponding authors and `<sup>#</sup>` for co-first authors. News and grants use a date line followed by an indented detail line; copy a nearby entry to keep the layout.

Preview with `bundle exec jekyll serve` at `http://127.0.0.1:4000/`. Local edits are not published until pushed.
