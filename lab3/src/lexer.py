from src.adt.buffer import ImmutableBuffer
from src.program import Program
from src.stuctures.pif import TokenType
from grammar import *
from errors import *
from typing import IO


def _detect_str(buffer: ImmutableBuffer, c: str) -> str:
    """ Detect and return a string literal. If it is not well-formed raise LexicalError.

    Note: The cursor of the buffer will be placed after the found string literal.

    Args:
        buffer (ImmutableBuffer): buffer of characters
        c (str): character that started the detection

    Returns: a string literal

    Raises:
        LexicalError: if string does not have a closing quote
    """
    token: str = c

    while c := buffer.get(1):
        # terminator found and break
        if c in STR_QUOTE:
            token += c
            break

        # invalid character found
        if c not in STR:
            # adjust the cursor such that it get the right line and column number
            # where the error has occurred
            buffer.put(1)
            raise LexicalError(f"string {token} is missing closing quote [{STR_QUOTE}]", buffer.line, buffer.col)

        # valid character found
        token += c

    return token


def _detect_int(buffer: ImmutableBuffer, c: str) -> str:
    """ Detect and returns an int literal. If it is the start of an identifier raise LexicalError.

    Note: The cursor of the buffer will be placed after the found int literal.

    Args:
        buffer (ImmutableBuffer): buffer of character
        c (str): character that started the detection

    Returns: an int literal

    Raises:
        LexicalError: if int is the start of an identifier
    """
    token: str = c

    while c := buffer.get(1):
        # invalid character found
        if c not in INT_CONTINUE:
            # the found character is part of an id
            if c in ID_CONTINUE:
                # adjust the cursor such that it get the right line and column number
                # where the error has occurred
                buffer.put(2)
                c = buffer.get(1)
                raise LexicalError(f"identifier cannot start with character [{c}]", buffer.line, buffer.col)
            # the found character is not part of an id
            # and the found int literal is valid
            buffer.put(1)
            break
        token += c

    return token


def _detect_special_token(buffer: ImmutableBuffer, c: str) -> str:
    """ Detects and returns a special token (operator / separator).

    Note: The cursor of the buffer will be placed after the found special token if one was found
    otherwise `c` will be put back.

    Args:
        buffer (ImmutableBuffer): buffer of characters
        c (str): character that started the detection

    Returns: a special token (operator / separator)
    """
    token: str = ""

    # place the character back
    buffer.put(1)

    # check if the next characters form a special token
    for special_token in SPECIAL_TOKENS:
        # get n characters from the buffer, where n is the length of the current special token
        temp: str = buffer.get(len(special_token))

        # check if the extracted characters form the current special token
        # if so, a special token has been found and break
        if temp == special_token:
            token = temp
            break

        # put the read characters back
        buffer.put(len(temp))

    return token


def _detect_id_or_keyword(buffer: ImmutableBuffer, c: str) -> str:
    """ Detect and return an id or a keyword.

    Note: The cursor of the buffer will be placed after the found id / keyword.

    Args:
        buffer (ImmutableBuffer): buffer of characters
        c (str): character that started the detection

    Returns: an id / a keyword
    """
    token: str = c

    while c := buffer.get(1):
        # invalid character was found
        if c not in ID_CONTINUE:
            buffer.put(1)
            break

        # valid character was found
        token += c

    return token


def scan(file: IO) -> Program:
    """ Lexically analyses the source code in the file. It returns a Program object
    containing the symbol table for ids and literals and the program internal form.

    Args:
        file (IO): opened file object

    Returns: a Program object

    Raises:
        LexicalError:
            if unexpected character was found
            if identifier does not start with proper character
            if string misses closing quotes
    """
    # init immutable buffer for easily parse the source code
    buffer: ImmutableBuffer = ImmutableBuffer(file.read())
    program: Program = Program()

    # start scanning
    while c := buffer.get(1):
        # skip whitespaces
        if c in WHITESPACE:
            continue

        # scan string literal
        if c in STR_QUOTE:
            token: str = _detect_str(buffer, c)

            # add it to the literal symbol table (if it does not exist already) and pif
            if not program.literal_symtable.contains(token):
                program.literal_symtable.add(token)
            program.pif.add(token, TokenType.LITERAL)

        # scan int literal
        elif c in INT_START:
            token: str = _detect_int(buffer, c)

            # add it to the literal symbol table (if it does not exist already) and pif
            if not program.literal_symtable.contains(token):
                program.literal_symtable.add(token)
            program.pif.add(token, TokenType.LITERAL)

        # scan operators / separators
        elif c in SPECIAL_TOKENS_START:
            token: str = _detect_special_token(buffer, c)

            # no special token found
            # this should not happen
            if len(token) == 0:
                assert False

            # classify token and add it to pif
            if token in OPERATORS:
                program.pif.add(token, TokenType.OPERATOR)
            elif token in SEPARATORS:
                program.pif.add(token, TokenType.SEPARATOR)
            else:
                # this should not happen
                assert False

        # scan ids / keywords
        elif c in ID_START:
            token: str = _detect_id_or_keyword(buffer, c)

            # classify token
            if token in KEYWORDS:
                # add it to pif
                program.pif.add(token, TokenType.KEYWORD)
            else:
                # add it to the id symbol table (if it does not exist already) and pif
                if not program.id_symtable.contains(token):
                    program.id_symtable.add(token)
                program.pif.add(token, TokenType.IDENTIFIER)

        # no token that starts with `c` could be detected
        else:
            raise LexicalError(f"unexpected character [{c}]", buffer.line, buffer.col)

    return program
