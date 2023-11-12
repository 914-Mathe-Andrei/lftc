import sys
import math

from src.lexer import scan
from src.structures.program import Program
from src.errors import LexicalError
from typing import IO


def main():
    program_path: str = "examples/p1err.mat"
    st_path: str = "examples/ST.out"
    pif_path: str = "examples/PIF.out"
    file: IO = open(program_path, 'r')

    try:
        # scan
        program: Program = scan(file)
        print("Lexically correct")

        # write ST.out
        with open(st_path, 'w') as file:
            spacing = 30

            # id symtable
            file.write(f"{'-' * spacing}\n")
            file.write(f"|{'IDS SYMTABLE':^{spacing - 2}}|\n")
            file.write(f"|{'-' * (spacing - 2)}|\n")
            for id in program.id_symtable.ids:
                file.write(f"| {id:^{spacing - 4}} |\n")
            file.write(f"{'-' * spacing}\n")

            file.write('\n')

            # literal symtable
            file.write(f"{'-' * spacing}\n")
            file.write(f"|{'LITERALS SYMTABLE':^{spacing -2}}|\n")
            file.write(f"|{'-' * (spacing - 2)}|\n")
            for literal in program.literal_symtable.literals:
                file.write(f"| {literal:^{spacing - 4}} |\n")
            file.write(f"{'-' * spacing}\n")

        # write PIF.out
        with open(pif_path, 'w') as file:
            spacing = 30

            file.write(f"{'-' * spacing}\n")
            file.write(f"|{'PIF':^{spacing - 2}}|\n")
            file.write(f"|{'-' * (spacing - 2)}|\n")
            for pair in program.pif.pairs:
                file.write(f"| {pair.token:<{math.ceil((spacing - 7) / 2)}} | {str(pair.type).split('.')[1]:<{math.floor((spacing - 7) / 2)}} |\n")
            file.write(f"{'-' * spacing}\n")

    except LexicalError as e:
        print(f"{e}", file=sys.stderr)


if __name__ == '__main__':
    main()
