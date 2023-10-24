import json
from dataclasses import dataclass
from typing import Any


class HashTable:
    @dataclass
    class Entry:
        key: Any
        value: Any

    def __init__(self, size: int = 1000):
        """ Initializes the hash table with array of size `size`.

        Args:
            size (int): the size of the array
        """
        self.__size: int = size                         # size of hash table's list
        self.__data: list[list[HashTable.Entry]] = [    # list of hash table entries of fixed size
            [] for _ in range(size)
        ]

    def __setitem__(self, key: Any, value: Any) -> None:
        """ Adds a new entry in hash table if key does not exist, otherwise it updates the value.

        Args:
            key (Any): key of the entry to be added / updated
            value (Any): value of the entry to be added / updated
        """
        # get hash value of key
        idx: int = self._hash(key)

        # check if key already exists
        # if so update its value
        for entry in self.__data[idx]:
            if entry.key == key:
                entry.value = value
                return

        # add the new entry
        new_entry = HashTable.Entry(key, value)
        self.__data[idx].append(new_entry)

    def __getitem__(self, key: Any) -> Any:
        """ Return the value associated with the key. If the key does not exist, it raises a KeyError.

        Args:
            key (Any): key in the hash table

        Returns: value associated with the key

        Raises:
            KeyError: the key does not exist in the hash table
        """
        # get hash value of key
        idx: int = self._hash(key)

        # check if key already exists
        # if so return the value
        for entry in self.__data[idx]:
            if entry.key == key:
                return entry.value

        # raise key error
        raise KeyError(f"Key {key} does not exist in the hash table!")

    def __delitem__(self, key: Any) -> None:
        """ Deleted the entry associated with the key. If the key does not exist, it raises a KeyError.

        Args:
            key (Any): key of the entry to be deleted

        Raises:
            KeyError: the key does not exist in the hash table
        """
        # get hash value of key
        idx: int = self._hash(key)

        # check if key already exists
        for entry in self.__data[idx]:
            if entry.key == key:
                self.__data[idx].remove(entry)
                return

        # raise key error
        raise KeyError(f"Key {key} does not exist in the hash table!")

    def __contains__(self, key: Any) -> bool:
        """ Checks if key is in the hash table.

        Args:
            key (Any): key to be checked

        Returns: True if key is in hash table, otherwise False
        """
        # get hash value of key
        idx: int = self._hash(key)

        # check if key already exists
        for entry in self.__data[idx]:
            if entry.key == key:
                return True

        return False

    def _hash(self, key: Any) -> int:
        """ Hashes the key and returns an integer value.

        The returned value will be in range 0 to size - 1, where "size" is the size of the hash table's array.

        Args:
            key (Any): key to be hashed

        Returns: the hash value (being an integer)
        """
        return hash(key) % self.__size

    def __str__(self):
        def serializer_custom_types(obj: Any):
            try:
                return json.JSONEncoder().encode(obj)
            except TypeError:
                return str(obj)

        # initialize a dictionary used as representation of the hash table
        dict_repr: dict[Any, Any] = {}

        # add the entries to the dictionary
        for list_ in self.__data:
            for entry in list_:
                dict_repr[entry.key] = entry.value

        # return the dictionary's string representation
        return json.dumps(dict_repr, indent=4, default=serializer_custom_types)
