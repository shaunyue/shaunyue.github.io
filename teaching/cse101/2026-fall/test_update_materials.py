"""运行：python3 -B -m unittest test_update_materials.py。"""
import json
from pathlib import Path
import tempfile
import unittest
from update_materials import render_rows, update


class MaterialsTest(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.folder = Path(self.temporary.name)
        self.chapter = {'number': 7, 'zh': '数组', 'en': 'Arrays', 'slides': '', 'code': '', 'videos': []}

    def test_video_labels_and_exact_urls(self):
        for count, labels in [(0, []), (1, ['[回放]']), (2, ['[上]', '[下]']),
                              (3, ['[上]', '[中]', '[下]']), (4, ['[回放1]', '[回放2]', '[回放3]', '[回放4]'])]:
            videos = [f'https://meeting.tencent.com/ctm/part{i}?a=1&b=2' for i in range(count)]
            row, links = render_rows([{**self.chapter, 'videos': videos}], self.folder)
            self.assertEqual(links, count)
            for label in labels:
                self.assertIn('>' + label + '</span>', row)
            for url in videos:
                self.assertIn(url.replace('&', '&amp;'), row)

    def test_valid_files_and_escaped_names(self):
        for directory, name in [('slides', 'lecture07.pdf'), ('code', 'chapter07.c')]:
            folder = self.folder / 'materials' / directory
            folder.mkdir(parents=True)
            (folder / name).write_text('source unchanged')
        row, links = render_rows([{**self.chapter, 'slides': 'lecture07.pdf', 'code': 'chapter07.c',
                                  'zh': '<script>"数组"</script>', 'en': 'Arrays & "Pointers"'}], self.folder)
        self.assertEqual(links, 2)
        self.assertIn(' download ', row)
        self.assertIn('target="_blank" rel="noopener"', row)
        self.assertNotIn('<script>', row)
        self.assertIn('&lt;script&gt;', row)
        self.assertIn('Arrays &amp; &quot;Pointers&quot;', row)

    def test_invalid_configuration_keeps_previous_page(self):
        index = self.folder / 'index.html'
        original = '<h1>Course</h1><table class="materials-table"><tbody>OLD</tbody></table>'
        index.write_text(original)
        slides = self.folder / 'materials/slides'
        slides.mkdir(parents=True)
        (slides / 'lecture07.pdf').write_text('source unchanged')
        invalid = [[self.chapter, self.chapter], [{**self.chapter, 'number': 0}],
                   [{**self.chapter, 'en': ''}], [{**self.chapter, 'video': []}],
                   [{**self.chapter, 'videos': ['javascript:alert(1)']}],
                   [{**self.chapter, 'slides': '../lecture07.pdf'}],
                   [{**self.chapter, 'slides': 'missing.pdf'}],
                   [{**self.chapter, 'slides': 'Lecture07.pdf'}],
                   [{**self.chapter, 'exercises': '../lecture07.pdf'}],
                   [{**self.chapter, 'exercises': 'missing.pdf'}],
                   [{**self.chapter, 'exercises': 'Lecture07.pdf'}],
                   [{**self.chapter, 'exercises': 'exercise.c'}],
                   [{**self.chapter, 'exercises': []}]]
        for chapters in invalid:
            (self.folder / 'materials.json').write_text(json.dumps(chapters))
            with self.assertRaises(ValueError):
                update(self.folder)
            self.assertEqual(index.read_text(), original)
        (self.folder / 'materials.json').write_text('[invalid')
        with self.assertRaises(json.JSONDecodeError):
            update(self.folder)
        self.assertEqual(index.read_text(), original)

    def test_exercises_share_slides_cell_and_are_optional(self):
        slides = self.folder / 'materials/slides'
        slides.mkdir(parents=True)
        (slides / 'lecture07.pdf').write_text('main slides unchanged')
        (slides / 'lecture07-exercises.pdf').write_text('exercise slides unchanged')
        row, links = render_rows([{**self.chapter, 'slides': 'lecture07.pdf',
                                  'exercises': 'lecture07-exercises.pdf'}], self.folder)
        self.assertEqual(links, 2)
        slides_cell = row.split('<td class="slides">')[1].split('</td>')[0]
        self.assertIn('href="materials/slides/lecture07.pdf"', slides_cell)
        self.assertIn('href="materials/slides/lecture07-exercises.pdf"', slides_cell)
        self.assertIn('data-en="[exercises]">[练习]</span>', slides_cell)
        self.assertIn('data-label-en="Chapter 7, Arrays: exercise slides PDF"', slides_cell)
        self.assertIn('target="_blank" rel="noopener"', slides_cell)
        self.assertNotIn(' download', slides_cell)
        self.assertEqual(row.count('<td'), 3)
        without, _ = render_rows([{**self.chapter, 'slides': 'lecture07.pdf'}], self.folder)
        empty, _ = render_rows([{**self.chapter, 'slides': 'lecture07.pdf', 'exercises': ''}], self.folder)
        self.assertEqual(without, empty)
        self.assertNotIn('[exercises]', without)

    def test_generation_is_repeatable_and_check_is_read_only(self):
        index = self.folder / 'index.html'
        index.write_text('<h1>Course</h1><table class="materials-table"><tbody>OLD</tbody></table><footer>End</footer>')
        (self.folder / 'materials.json').write_text(json.dumps([self.chapter]))
        with self.assertRaises(ValueError):
            update(self.folder, check=True)
        self.assertIn('OLD', index.read_text())
        self.assertEqual(update(self.folder), (1, 0))
        rendered = index.read_text()
        self.assertEqual(update(self.folder, check=True), (1, 0))
        self.assertEqual(update(self.folder), (1, 0))
        self.assertEqual(index.read_text(), rendered)
        self.assertTrue(rendered.startswith('<h1>Course</h1>'))
        self.assertTrue(rendered.endswith('<footer>End</footer>'))


if __name__ == '__main__':
    unittest.main()
