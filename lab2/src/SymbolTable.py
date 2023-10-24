from HashTable import HashTable
from Type import Type
from dataclasses import dataclass
from typing import Any


@dataclass
class Identifier:
    name: str
    type: Type
    value: Any

@dataclass
class Const:
    value: Any
    type: Type


class IdentifierSymbolTable:
    def __init__(self):
        self.__table: HashTable = HashTable()

    def insert(self, id: str, type: Type, value: Any) -> None:
        if id in self.__table:
            raise KeyError(f"Identifier {id} already exists in the symbol table!")
        self.__table[id] = Identifier(id, type, value)

    def update(self, id: str, value: Any) -> None:
        if id not in self.__table:
            raise KeyError(f"Identifier {id} does not exist in the symbol table!")
        identifier: Identifier = self.__table[id]
        identifier.value = value

    def get(self, id: str) -> Identifier:
        if id not in self.__table:
            raise KeyError(f"Identifier {id} does not exist in the symbol table!")
        return self.__table[id]

    def delete(self, id: str) -> None:
        if id not in self.__table:
            raise KeyError(f"Identifier {id} does not exist in the symbol table!")
        del self.__table[id]

    def contains(self, id: str) -> bool:
        return id in self.__table

    def __str__(self):
        return str(self.__table)


class ConstSymbolTable():
    def __init__(self):
        self.__table: HashTable = HashTable()

    def insert(self, const: Any, type: Type) -> None:
        if const in self.__table:
            raise KeyError(f"Constant {const} already exists in the symbol table!")
        self.__table[const] = Const(const, type)

    def get(self, const: Any) -> Const:
        if const not in self.__table:
            raise KeyError(f"Constant {const} does not exist in the symbol table!")
        return self.__table[const]

    def delete(self, const: Any) -> None:
        if const not in self.__table:
            raise KeyError(f"Constant {const} does not exist in the symbol table!")
        del self.__table[const]

    def contains(self, const: Any) -> bool:
        return const in self.__table

    def __str__(self):
        return str(self.__table)
