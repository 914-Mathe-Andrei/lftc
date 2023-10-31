from src.adt.hash_table import HashTable
from src.errors import SymTableError
from typing import Any


class IdSymTable:
    """ Symbol table for identifiers. """

    def __init__(self):
        self.__table: HashTable = HashTable()

    def add(self, id: str) -> None:
        """ Add a new identifier.

        Args:
            id (str): id

        Raises:
            SymTableError: if `id` already exists in the table
        """
        if id in self.__table:
            raise SymTableError(f"Identifier {id} already exists in the symbol table!")
        self.__table[id] = None

    def delete(self, id: str) -> None:
        """ Removes an id.

        Args:
            id (str): id

        Raises:
            SymTableError: if `id` does not exist in the table
        """
        if id not in self.__table:
            raise SymTableError(f"Identifier {id} does not exist in the symbol table!")
        del self.__table[id]

    def contains(self, id: str) -> bool:
        """ Checks if an id is in the table.

        Args:
            id (str): id

        Returns: True if `id` exists else False
        """
        return id in self.__table

    @property
    def ids(self) -> list[str]:
        """ Returns a list of all the ids in the table. """
        return list(map(lambda x: x.key, self.__table.entries))

    def __str__(self):
        return str(self.__table)


class LiteralSymTable:
    """ Symbol table for literals. """

    def __init__(self):
        self.__table: HashTable = HashTable()

    def add(self, literal: Any) -> None:
        """ Adds a new literal.

        Args:
            literal (Any): literal

        Raises:
            SymTableError: if `literal` already exists in the table
        """
        if literal in self.__table:
            raise SymTableError(f"Literal {literal} already exists in the symbol table!")
        self.__table[literal] = None

    def delete(self, literal: Any) -> None:
        """ Removes a literal.

        Args:
            literal (Any): literal

        Raises:
            SymTableError: if `literal` does not exist in the table
        """
        if literal not in self.__table:
            raise SymTableError(f"Literal {literal} does not exist in the symbol table!")
        del self.__table[literal]

    def contains(self, literal: Any) -> bool:
        """ Check if a literal is in the table.

        Args:
            literal (Any): literal

        Returns: True if `literal` exists else False
        """
        return literal in self.__table

    @property
    def literals(self) -> list[str]:
        """ Returns a list of all the literals in the table. """
        return list(map(lambda x: x.key, self.__table.entries))

    def __str__(self):
        return str(self.__table)
