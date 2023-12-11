import unittest

from src.structures.pif import ProgramInternalForm, TokenType


class ProgramInternalFormTestCase(unittest.TestCase):
    def setUp(self):
        self.pif = ProgramInternalForm()
    
    def test_add(self):
        self.pif.add('var', TokenType.KEYWORD)
        self.pif.add('cat', TokenType.IDENTIFIER)
        self.pif.add(':', TokenType.SEPARATOR)
        self.pif.add('str', TokenType.KEYWORD)
        self.pif.add('=', TokenType.OPERATOR)
        self.pif.add('ursulica', TokenType.LITERAL)

        self.assertListEqual(self.pif.pairs, [
            ProgramInternalForm.Entry('var', TokenType.KEYWORD),
            ProgramInternalForm.Entry('cat', TokenType.IDENTIFIER),
            ProgramInternalForm.Entry(':', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('str', TokenType.KEYWORD),
            ProgramInternalForm.Entry('=', TokenType.OPERATOR),
            ProgramInternalForm.Entry('ursulica', TokenType.LITERAL)
        ])

    def test_str(self):
        self.assertEqual(str(self.pif), '')
