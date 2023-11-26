from dataclasses import dataclass
from enum import Enum


class TokenType(Enum):
    """ Classes of tokens. """
    IDENTIFIER = 1
    LITERAL = 2
    OPERATOR = 3
    SEPARATOR = 4
    KEYWORD = 5


class ProgramInternalForm:
    @dataclass
    class Entry:
        """ An entry in the PIF. """
        token: str
        type: TokenType

    def __init__(self):
        self.__pairs: list[ProgramInternalForm.Entry] = []  # pairs of the pif

    @property
    def pairs(self) -> list["ProgramInternalForm.Entry"]:
        """ Returns a list of pif pairs. """
        return self.__pairs

    def add(self, token: str, type: TokenType) -> None:
        """ Adds a token pair.

        Args:
            token (str): token
            type (TokenType): type of token (id / literal / operator / separator / keyword)
        """
        pair: ProgramInternalForm.Entry = self.Entry(token, type)
        self.__pairs.append(pair)

    def __str__(self):
        """ Returns a string containing all the pairs separated by newline. """
        return '\n'.join(
            f"({pair.token}, {pair.type})" for pair in self.__pairs
        )
