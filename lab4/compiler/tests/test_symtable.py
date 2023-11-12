import json
import unittest

from src.errors import SymTableError
from src.structures.symtable import IdSymTable, LiteralSymTable


class IdSymTableTestCase(unittest.TestCase):
    def setUp(self):
        self.symtable = IdSymTable()

    def test_add(self):
        self.symtable.add('a')
        self.assertTrue(self.symtable.contains('a'))

        with self.assertRaises(SymTableError):
            self.symtable.add('a')

    def test_delete(self):
        with self.assertRaises(SymTableError):
            self.symtable.delete('a')

        self.symtable.add('a')
        self.assertTrue(self.symtable.contains('a'))
        self.symtable.delete('a')
        self.assertFalse(self.symtable.contains('a'))

    def test_ids(self):
        self.symtable.add('a')
        self.symtable.add('b')

        self.assertListEqual(sorted(self.symtable.ids), ['a', 'b'])

    def test_str(self):
        self.symtable.add('a')
        self.assertEqual(str(self.symtable), json.dumps({'a': None}, indent=4))


class LiteralSymTableTestCase(unittest.TestCase):
    def setUp(self):
        self.symtable = LiteralSymTable()

    def test_add(self):
        self.symtable.add('1')
        self.assertTrue(self.symtable.contains('1'))

        with self.assertRaises(SymTableError):
            self.symtable.add('1')

    def test_delete(self):
        with self.assertRaises(SymTableError):
            self.symtable.delete('1')

        self.symtable.add('1')
        self.assertTrue(self.symtable.contains('1'))
        self.symtable.delete('1')
        self.assertFalse(self.symtable.contains('1'))

    def test_ids(self):
        self.symtable.add('1')
        self.symtable.add('"ursulica"')

        self.assertListEqual(sorted(self.symtable.literals), ['"ursulica"', '1'])

    def test_str(self):
        self.symtable.add('1')
        self.assertEqual(str(self.symtable), json.dumps({'1': None}, indent=4))
