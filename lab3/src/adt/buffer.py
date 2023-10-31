class ImmutableBuffer:
    """ A buffer whose data can not be modified but can be parsed. """

    def __init__(self, data: str):
        self.__data: str = data     # data of the buffer
        self.__pos: int = 0         # position of the cursor

    @property
    def line(self) -> int:
        """ Returns the line number where the cursor is currently at.

        Returns: the line number
        """
        # count the numbers of newline till cursor position
        return self.__data[:self.__pos].count('\n') + 1

    @property
    def col(self) -> int:
        """ Returns the column number where the cursor is currently at.

        Returns: the column number
        """
        # count the numbers of characters from cursor position to beginning
        # until newline character is found
        result: int = 0
        for c in reversed(self.__data[:self.__pos]):
            if c in '\n':
                break
            result += 1
        return result

    def get(self, size: int | None = None) -> str:
        """ Returns the next `size` characters in a string.

        If `size` is None than it will read all the remaining characters.

        Args:
            size (int | None): number of characters to read

        Returns: the read characters

        Raises:
            ValueError: if `size` is a negative number
        """
        # if size is None than get all the remaining characters
        if size is None:
            size = len(self.__data)

        # if size is negative raise error
        if size < 0:
            raise ValueError(f"Invalid value {size} for `size`! Cannot be negative!")

        # get the characters in a string
        data: str = self.__data[self.__pos:self.__pos + size]

        # update the cursor position
        # if all characters in the buffer have been read then place the cursor at the end
        # otherwise just move it forward `size` characters
        if self.__pos + size >= len(self.__data):
            self.__pos = len(self.__data)
        else:
            self.__pos += size

        return data

    def put(self, size: int | None = None) -> None:
        """ Puts back `size` characters in the buffer. It actually moves the cursor `size` characters back.

        Args:
            size (int | None): number of characters

        Raises:
            ValueError: if `size` is a negative number
        """
        # if size is None than do nothing
        if size is None:
            self.__pos = 0
            return

        # if size is negative raise error
        if size < 0:
            raise ValueError(f"Invalid value {size} for `size`! Cannot be negative!")

        # update the cursor position
        # if all the characters are put back then place the cursor at the start
        # otherwise just move it back `size` characters
        if self.__pos - size < 0:
            self.__pos = 0
        else:
            self.__pos -= size

    def __len__(self):
        """ Returns the length of the buffer. """
        return len(self.__data)
