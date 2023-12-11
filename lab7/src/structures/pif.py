import math
from pathlib import Path
from enum import Enum
from dataclasses import dataclass


class TokenType(Enum):
    """ Classes of tokens. """
    IDENTIFIER = 'IDENTIFIER'
    LITERAL = 'LITERAL'
    OPERATOR = 'OPERATOR'
    SEPARATOR = 'SEPARATOR'
    KEYWORD = 'KEYWORD'


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

    def load(self, filepath: str | Path) -> None:
        """ Loads the pif data from a file.

        Args:
            filepath (str | Path): path to file
        """
        with open(filepath, 'r') as file:
            lines = file.readlines()
            for line in lines:
                line = line.strip()
                if line == '':
                    continue

                token, token_type_str = line.split()
                self.add(token, TokenType(token_type_str))

    def dump(self, filepath: str | Path, pretty: bool = False) -> None:
        """ Dumps the pif data to a file.

        Args:
            filepath (str | Path): path to file
            pretty (bool): flag to pretty print
        """
        with open(filepath, 'w') as file:
            if pretty:
                spacing = 30
                file.write(f"{'-' * spacing}\n")
                file.write(f"|{'PIF':^{spacing - 2}}|\n")
                file.write(f"|{'-' * (spacing - 2)}|\n")
                for pair in self.pairs:
                    file.write(f"| {pair.token:<{math.ceil((spacing - 7) / 2)}} | {str(pair.type).split('.')[1]:<{math.floor((spacing - 7) / 2)}} |\n")
                file.write(f"{'-' * spacing}\n")
            else:
                file.write('\n'.join(f"{pair.token} {pair.type.value}" for pair in self.__pairs))

    def __str__(self):
        """ Returns a string containing all the pairs separated by newline. """
        return '\n'.join(
            f"({pair.token}, {pair.type})" for pair in self.__pairs
        )
