class SymTableError(Exception):
    """ Symbol table related error. """
    pass


class LexicalError(Exception):
    """ Lexical analysis error. """
    def __init__(self, message: str, line: int, col: int):
        self.message: str = message     # error message
        self.line: int = line           # line number where error occurred
        self.col: int = col             # column number where error occurred

    def __str__(self):
        return f"LexicalError at {self.line}:{self.col}: {self.message}"
