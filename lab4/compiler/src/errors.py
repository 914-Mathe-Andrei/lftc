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


class InvalidSymbol(Exception):
    """ Finite Automata error when symbol found is invalid. """
    def __init__(self, message: str, symbol: str, line: int, col: int):
        self.message: str = message     # error message
        self.symbol: str = symbol       # symbol that caused the error
        self.line: int = line           # line number where error occurred
        self.col: int = col             # column number where error occurred


class InvalidSequence(Exception):
    """ Finite Automata error when sequence found is not accepted. """
    def __init__(self, message: str, line: int, col: int):
        self.message: str = message     # error message
        self.line: int = line           # line number where error occurred
        self.col: int = col             # column number where error occurred