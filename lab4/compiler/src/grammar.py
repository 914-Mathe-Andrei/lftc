WHITESPACE = ' \n\r\t'
UNDERSCORE = '_'

UPPERCASE_LETTER = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
LOWERCASE_LETTER = 'abcdefghijklmnopqrstuvwxyz'
LETTER = UPPERCASE_LETTER + LOWERCASE_LETTER

ZERO_DIGIT = '0'
NONZERO_DIGIT = '123456789'
DIGIT = ZERO_DIGIT + NONZERO_DIGIT

ID_START = (
    LETTER +
    UNDERSCORE
)
ID_CONTINUE = (
    LETTER +
    DIGIT +
    UNDERSCORE
)

INT = DIGIT

STR_QUOTE = '"'
STR = (
    LETTER +
    DIGIT
)

OPERATORS = sorted([
    '+',
    '-',
    '*',
    '/',
    '%',
    '=',
    '==',
    '!=',
    '!',
    '&&',
    '||',
    '<',
    '<=',
    '>',
    '>=',
    '.'
], key=lambda x: len(x), reverse=True)

SEPARATORS = sorted([
    '(',
    ')',
    '[',
    ']',
    '{',
    '}',
    ':',
    ';',
    ',',
    '->',
], key=lambda x: len(x), reverse=True)

KEYWORDS = [
    'int',
    'str',
    'var',
    'const',
    'if',
    'else',
    'while',
    'read',
    'write',
    'fn',
    'return'
]

SPECIAL_TOKENS = sorted([
    *OPERATORS,
    *SEPARATORS,
], key=lambda x: len(x), reverse=True)

SPECIAL_TOKENS_START = set(map(lambda x: x[0], SPECIAL_TOKENS))
