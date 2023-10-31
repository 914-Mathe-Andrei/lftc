import io
import textwrap
import unittest

from src import lexer
from src.errors import LexicalError
from src.stuctures.pif import ProgramInternalForm, TokenType


class LexerTestCase(unittest.TestCase):
    def setUp(self):
        self.source_code_1 = textwrap.dedent("""\
        fn main() -> int {
            max(1, 2, 3);
            
            "test"
            
            if (1 > 0) {
            } else {
            }
            
            ABCDEFGHIJKLMNOPQRSTUVWXYZ
            abcdefghijklmnopqrstuvwxyz
            _
            1234567890
            +
            -
            *
            /
            %
            =
            ==
            !=
            !
            &&
            ||
            <
            <=
            >
            >=
            (
            )
            [
            ]
            {
            }
            :
            ;
            ,
            ->
            int
            str
            var
            const
            while
            read
            write
            
            return 1;
        }
        """)

        # unexpected character found
        self.source_code_2 = textwrap.dedent("""\
        fn main() -> int { $
            max(1, 2, 3);
            
            return 1;
        }
        """)

        # unterminated string literal
        self.source_code_3 = textwrap.dedent("""\
        fn main() -> int {
            "abc
        """)

        self.source_code_4 = textwrap.dedent("""\
        fn main() -> int {
            1abc

            return 1;
        }
        """)

        self.source_code_5 = textwrap.dedent("""\
        fn main() -> int {
            0001

            return 1;
        }
        """)

    def test_scan(self):
        fake_file = io.StringIO(self.source_code_1)
        program = lexer.scan(fake_file)

        self.assertEqual(program.pif.pairs, [
            ProgramInternalForm.Entry('fn', TokenType.KEYWORD),
            ProgramInternalForm.Entry('main', TokenType.IDENTIFIER),
            ProgramInternalForm.Entry('(', TokenType.SEPARATOR),
            ProgramInternalForm.Entry(')', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('->', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('int', TokenType.KEYWORD),
            ProgramInternalForm.Entry('{', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('max', TokenType.IDENTIFIER),
            ProgramInternalForm.Entry('(', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('1', TokenType.LITERAL),
            ProgramInternalForm.Entry(',', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('2', TokenType.LITERAL),
            ProgramInternalForm.Entry(',', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('3', TokenType.LITERAL),
            ProgramInternalForm.Entry(')', TokenType.SEPARATOR),
            ProgramInternalForm.Entry(';', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('"test"', TokenType.LITERAL),
            ProgramInternalForm.Entry('if', TokenType.KEYWORD),
            ProgramInternalForm.Entry('(', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('1', TokenType.LITERAL),
            ProgramInternalForm.Entry('>', TokenType.OPERATOR),
            ProgramInternalForm.Entry('0', TokenType.LITERAL),
            ProgramInternalForm.Entry(')', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('{', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('}', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('else', TokenType.KEYWORD),
            ProgramInternalForm.Entry('{', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('}', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('ABCDEFGHIJKLMNOPQRSTUVWXYZ', TokenType.IDENTIFIER),
            ProgramInternalForm.Entry('abcdefghijklmnopqrstuvwxyz', TokenType.IDENTIFIER),
            ProgramInternalForm.Entry('_', TokenType.IDENTIFIER),
            ProgramInternalForm.Entry('1234567890', TokenType.LITERAL),
            ProgramInternalForm.Entry('+', TokenType.OPERATOR),
            ProgramInternalForm.Entry('-', TokenType.OPERATOR),
            ProgramInternalForm.Entry('*', TokenType.OPERATOR),
            ProgramInternalForm.Entry('/', TokenType.OPERATOR),
            ProgramInternalForm.Entry('%', TokenType.OPERATOR),
            ProgramInternalForm.Entry('=', TokenType.OPERATOR),
            ProgramInternalForm.Entry('==', TokenType.OPERATOR),
            ProgramInternalForm.Entry('!=', TokenType.OPERATOR),
            ProgramInternalForm.Entry('!', TokenType.OPERATOR),
            ProgramInternalForm.Entry('&&', TokenType.OPERATOR),
            ProgramInternalForm.Entry('||', TokenType.OPERATOR),
            ProgramInternalForm.Entry('<', TokenType.OPERATOR),
            ProgramInternalForm.Entry('<=', TokenType.OPERATOR),
            ProgramInternalForm.Entry('>', TokenType.OPERATOR),
            ProgramInternalForm.Entry('>=', TokenType.OPERATOR),
            ProgramInternalForm.Entry('(', TokenType.SEPARATOR),
            ProgramInternalForm.Entry(')', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('[', TokenType.SEPARATOR),
            ProgramInternalForm.Entry(']', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('{', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('}', TokenType.SEPARATOR),
            ProgramInternalForm.Entry(':', TokenType.SEPARATOR),
            ProgramInternalForm.Entry(';', TokenType.SEPARATOR),
            ProgramInternalForm.Entry(',', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('->', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('int', TokenType.KEYWORD),
            ProgramInternalForm.Entry('str', TokenType.KEYWORD),
            ProgramInternalForm.Entry('var', TokenType.KEYWORD),
            ProgramInternalForm.Entry('const', TokenType.KEYWORD),
            ProgramInternalForm.Entry('while', TokenType.KEYWORD),
            ProgramInternalForm.Entry('read', TokenType.KEYWORD),
            ProgramInternalForm.Entry('write', TokenType.KEYWORD),
            ProgramInternalForm.Entry('return', TokenType.KEYWORD),
            ProgramInternalForm.Entry('1', TokenType.LITERAL),
            ProgramInternalForm.Entry(';', TokenType.SEPARATOR),
            ProgramInternalForm.Entry('}', TokenType.SEPARATOR),
        ])

        self.assertEqual(sorted(program.id_symtable.ids), [
            'ABCDEFGHIJKLMNOPQRSTUVWXYZ',
            '_',
            'abcdefghijklmnopqrstuvwxyz',
            'main',
            'max'
        ])

        self.assertEqual(sorted(program.literal_symtable.literals), [
            '"test"',
            '0',
            '1',
            '1234567890',
            '2',
            '3'
        ])

        with self.assertRaises(LexicalError) as cm:
            fake_file = io.StringIO(self.source_code_2)
            _ = lexer.scan(fake_file)
        self.assertEqual(str(cm.exception), 'LexicalError at 1:20: unexpected character [$]')

        with self.assertRaises(LexicalError) as cm:
            fake_file = io.StringIO(self.source_code_3)
            _ = lexer.scan(fake_file)
        self.assertEqual(str(cm.exception), 'LexicalError at 2:5: unterminated string literal \"abc')

        with self.assertRaises(LexicalError) as cm:
            fake_file = io.StringIO(self.source_code_4)
            _ = lexer.scan(fake_file)
        self.assertEqual(str(cm.exception), 'LexicalError at 2:6: invalid character [a] in int literal 1a')

        with self.assertRaises(LexicalError) as cm:
            fake_file = io.StringIO(self.source_code_5)
            _ = lexer.scan(fake_file)
        self.assertEqual(str(cm.exception), 'LexicalError at 2:6: leading zeros in int literal are not permitted')
