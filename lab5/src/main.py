from src import parser
from src.structures.grammar import Grammar


def print_menu() -> None:
    print("Menu:")
    print("1. display start nonterminal")
    print("2. display terminals")
    print("3. display nonterminals")
    print("4. display all productions")
    print("5. display production for a nonterminal")
    print("6. check if grammar is cfg")
    print("x. exit")


def print_start_nonterminal(grammar: Grammar) -> None:
    print(grammar.start)


def print_terminals(grammar: Grammar) -> None:
    print('\n'.join(f"\t{terminal}" for terminal in grammar.terminals))


def print_nonterminals(grammar: Grammar) -> None:
    print('\n'.join(f"\t{nonterminal}" for nonterminal in grammar.nonterminals))


def print_productions(grammar: Grammar) -> None:
    for nonterminal in grammar.nonterminals:
        print_productions_for_nonterminal(grammar, nonterminal)


def print_productions_for_nonterminal(grammar: Grammar, nonterminal: str) -> None:
    def _production_to_str(production: list[str]) -> str:
        result = ''
        for idx, elem in enumerate(production):
            if elem in ['ID', 'INT', 'STR']:
                result += elem.lower()
            elif elem in grammar.terminals:
                result += '"' + elem + '"'
            else:
                result += elem

            if idx != len(production) - 1:
                result += ' '
        return result

    print(f"\t{nonterminal} -> ", end='')
    print(' | '.join(_production_to_str(production) for production in grammar.productions[nonterminal]))


def print_check_cfg(grammar: Grammar) -> None:
    print(f"grammar {'is' if grammar.is_cfg() else 'is not'} a CFG")


def run(grammar: Grammar) -> None:
    while True:
        print_menu()

        option: str = input('\n> Choose an option: ').strip()
        if option == 'x':
            break

        match option:
            case '1':
                print_start_nonterminal(grammar)
            case '2':
                print_terminals(grammar)
            case '3':
                print_nonterminals(grammar)
            case '4':
                print_productions(grammar)
            case '5':
                nonterminal: str = input('> Enter a nonterminal: ').strip()
                print_productions_for_nonterminal(grammar, nonterminal)
            case '6':
                print_check_cfg(grammar)
            case _:
                print('Invalid option!')

        print()


def main():
    syntax_path: str = 'input/g2.toml'
    parser.parse(syntax_path)

    # # run menu
    # grammar = Grammar(syntax_path)
    # run(grammar)

    # program_path: str = "examples/p1.mat"
    # st_path: str = "examples/ST.out"
    # pif_path: str = "examples/PIF.out"
    # file: IO = open(program_path, 'r')
    #
    # try:
    #     # scan
    #     program: Program = scan(file)
    #     print("Lexically correct")
    #
    #     # write ST.out
    #     with open(st_path, 'w') as file:
    #         spacing = 30
    #
    #         # id symtable
    #         file.write(f"{'-' * spacing}\n")
    #         file.write(f"|{'IDS SYMTABLE':^{spacing - 2}}|\n")
    #         file.write(f"|{'-' * (spacing - 2)}|\n")
    #         for id in program.id_symtable.ids:
    #             file.write(f"| {id:^{spacing - 4}} |\n")
    #         file.write(f"{'-' * spacing}\n")
    #
    #         file.write('\n')
    #
    #         # literal symtable
    #         file.write(f"{'-' * spacing}\n")
    #         file.write(f"|{'LITERALS SYMTABLE':^{spacing -2}}|\n")
    #         file.write(f"|{'-' * (spacing - 2)}|\n")
    #         for literal in program.literal_symtable.literals:
    #             file.write(f"| {literal:^{spacing - 4}} |\n")
    #         file.write(f"{'-' * spacing}\n")
    #
    #     # write PIF.out
    #     with open(pif_path, 'w') as file:
    #         spacing = 30
    #
    #         file.write(f"{'-' * spacing}\n")
    #         file.write(f"|{'PIF':^{spacing - 2}}|\n")
    #         file.write(f"|{'-' * (spacing - 2)}|\n")
    #         for pair in program.pif.pairs:
    #             file.write(f"| {pair.token:<{math.ceil((spacing - 7) / 2)}} | {str(pair.type).split('.')[1]:<{math.floor((spacing - 7) / 2)}} |\n")
    #         file.write(f"{'-' * spacing}\n")
    #
    # except LexicalError as e:
    #     print(f"{e}", file=sys.stderr)


if __name__ == '__main__':
    main()
