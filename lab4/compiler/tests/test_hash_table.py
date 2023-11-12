import json
import unittest

from src.adt.hash_table import HashTable


class HashTableTestCase(unittest.TestCase):
    def setUp(self):
        self.table = HashTable()

    def test_setitem(self):
        self.table['a'] = 1
        self.table['b'] = 2

        self.assertEqual(len(self.table), 2)
        self.assertListEqual(sorted(self.table.entries, key=lambda x: x.key), [HashTable.Entry('a', 1), HashTable.Entry('b', 2)])

        self.table['b'] = 3

        self.assertEqual(len(self.table), 2)
        self.assertListEqual(sorted(self.table.entries, key=lambda x: x.key), [HashTable.Entry('a', 1), HashTable.Entry('b', 3)])

    def test_getitem(self):
        self.table['a'] = 1

        self.assertEqual(self.table['a'], 1)

        with self.assertRaises(KeyError):
            r = self.table['b']

    def test_delitem(self):
        self.table['a'] = 1

        del self.table['a']
        self.assertEqual(len(self.table.entries), 0)

        with self.assertRaises(KeyError):
            r = self.table['a']

        with self.assertRaises(KeyError):
            del self.table['a']

    def test_contains(self):
        self.table['a'] = 1

        self.assertTrue('a' in self.table)
        self.assertFalse('b' in self.table)

    def test_str(self):
        self.table['a'] = 1
        self.assertEqual(str(self.table), json.dumps({'a': 1}, indent=4))
