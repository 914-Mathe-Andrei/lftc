import unittest

from src.adt.buffer import ImmutableBuffer


class ImmutableBufferTestCase(unittest.TestCase):
    def setUp(self):
        self.buffer = ImmutableBuffer("var a: int = 5;\nwrite a;\nreturn 0;")

    def test_line(self):
        self.assertEqual(self.buffer.line, 1)
        self.buffer.get(16)
        self.assertEqual(self.buffer.line, 2)
        self.buffer.get(1)
        self.assertEqual(self.buffer.line, 2)
        self.buffer.get(10)
        self.assertEqual(self.buffer.line, 3)

    def test_col(self):
        self.assertEqual(self.buffer.col, 1)
        self.buffer.get(10)
        self.assertEqual(self.buffer.col, 11)
        self.buffer.get(6)
        self.assertEqual(self.buffer.col, 1)

    def test_get(self):
        token = self.buffer.get(1)
        self.assertEqual(token, 'v')

        self.assertEqual(self.buffer.line, 1)
        self.assertEqual(self.buffer.col, 2)

        token = self.buffer.get()
        self.assertEqual(token, 'ar a: int = 5;\nwrite a;\nreturn 0;')
        self.assertEqual(self.buffer.line, 3)
        self.assertEqual(self.buffer.col, 10)

        token = self.buffer.get(1000)
        self.assertEqual(token, '')
        self.assertEqual(self.buffer.line, 3)
        self.assertEqual(self.buffer.col, 10)

        with self.assertRaises(ValueError):
            _ = self.buffer.get(-1)

    def test_put(self):
        self.buffer.put(1000)
        self.assertEqual(self.buffer.line, 1)
        self.assertEqual(self.buffer.col, 1)

        self.buffer.get(17)
        self.assertEqual(self.buffer.line, 2)
        self.assertEqual(self.buffer.col, 2)

        self.buffer.put(1)
        self.assertEqual(self.buffer.line, 2)
        self.assertEqual(self.buffer.col, 1)

        self.buffer.put()
        self.assertEqual(self.buffer.line, 1)
        self.assertEqual(self.buffer.col, 1)

        with self.assertRaises(ValueError):
            self.buffer.put(-1)

    def test_len(self):
        self.assertEqual(len(self.buffer), 34)
