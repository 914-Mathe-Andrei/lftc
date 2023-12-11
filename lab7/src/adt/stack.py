from typing import Any


class Stack:
    def __init__(self, data: list[Any] = []):
        self.__data: list[Any] = data

    def top(self) -> Any:
        return self.__data[-1]

    def push(self, elements: list[Any]) -> None:
        self.__data.extend(elements)

    def pop(self, k: int) -> list[Any]:
        if k < 1:
            raise ValueError(f"must pop at least one element")
        elements = self.__data[-k:]
        del self.__data[-k:]
        return elements

    def __len__(self):
        return len(self.__data)

    def __str__(self):
        return str(self.__data)
