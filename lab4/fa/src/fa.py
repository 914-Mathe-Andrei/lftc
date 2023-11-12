import tomllib
from dataclasses import dataclass


class FiniteAutomata:
    @dataclass
    class State:
        name: str
        transitions: dict[str, "FiniteAutomata.State"]

    def __init__(self, filepath: str):
        self.alphabet: list[str] = []
        self.states: dict[str, FiniteAutomata.State] = {}

        self.initial_state: FiniteAutomata.State = None
        self.final_states: list[FiniteAutomata.State] = []

        self._load(filepath)

    def _load(self, filepath: str) -> None:
        data: dict = None

        # read fa config file
        with open(filepath, 'rb') as file:
            data = tomllib.load(file)

        self.alphabet = data['alphabet']

        for state in data['states']:
            name = state['name']
            self.states[name] = FiniteAutomata.State(name, {})

        for state in data['states']:
            name = state['name']
            for transition in state['transitions']:
                symbol = transition['symbol']
                next_state = transition['next_state']
                if next_state not in self.states:
                    raise KeyError(f"Transition ({name}, {symbol}) has as next state {next_state}, but {next_state} was not found in the set of states!")
                self.states[name].transitions[symbol] = self.states[next_state]

        self.initial_state = self.states[data['initial_state']]

        for final_state in data['final_states']:
            if final_state not in self.states:
                raise KeyError(f"Final state {final_state} was not found in the set of states!")
            self.final_states.append(self.states[final_state])

    def check_acceptance(self, sequence: str) -> bool:
        current_state = self.initial_state

        for symbol in sequence:
            if symbol not in self.alphabet:
                return False
            if symbol not in current_state.transitions:
                return False
            current_state = current_state.transitions[symbol]

        if current_state not in self.final_states:
            return False

        return True
