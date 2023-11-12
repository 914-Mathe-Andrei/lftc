from src.fa import (FiniteAutomata)


def print_menu():
    """ Prints the menu. """
    print(f"Menu:")
    print(f"\t1. display alphabet")
    print(f"\t2. display states")
    print(f"\t3. display initial state")
    print(f"\t4. display final states")
    print(f"\t5. display transitions")
    print(f"\t6. check acceptance of language")
    print(f"\tx. exit")
    print()


def main():
    fa_path = 'input/fa_identifier.toml'
    fa = FiniteAutomata(fa_path)

    # loop for the menu driven interface
    while True:
        # print menu
        print_menu()

        # let user choose an option
        option = input("> Choose an option: ").strip()

        # check if user wants to quit
        if option == 'x':
            break

        # to the thingies
        match option:
            case '1':
                print('\n'.join(f"- {symbol}" for symbol in fa.alphabet))
            case '2':
                print('\n'.join(f"- {state}" for state in fa.states))
            case '3':
                print(fa.initial_state.name)
            case '4':
                print('\n'.join(f"- {state.name}" for state in fa.final_states))
            case '5':
                for state in fa.states.values():
                    print(f"From state {state.name}:")
                    for symbol, next_state in state.transitions.items():
                        print(f"\t- δ({state.name}, {symbol}) = {next_state.name}")
                    print()
            case '6':
                sequence = input("Write a sequence:\n> ")
                accepted: bool = fa.check_acceptance(sequence)
                print("Accepted!" if accepted else "Rejected!")
            case _:
                print("Invalid option!")

        print()


if __name__ == '__main__':
    main()
