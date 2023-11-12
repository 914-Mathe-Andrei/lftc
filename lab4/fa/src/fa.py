import tomllib
from dataclasses import dataclass


class FiniteAutomata:
    """ Represents a finite automaton. """

    @dataclass
    class State:
        """ Represents the state of a finite automaton. """
        name: str
        transitions: dict[str, "FiniteAutomata.State"]

    def __init__(self, filepath: str):
        """ Initializes the FA described in `filepath`.

        Args:
            filepath: path to a TOML file
        """
        self.alphabet: list[str] = []                       # alphabet of FA
        self.states: dict[str, FiniteAutomata.State] = {}   # states of FA as key-value pairs where key is state name and value is State instance

        self.initial_state: FiniteAutomata.State = None     # initial state of FA as Stance instance
        self.final_states: list[FiniteAutomata.State] = []  # final states of FA as list of State instances

        # load the TOML file and init the FA elements
        self._load(filepath)

    def _load(self, filepath: str) -> None:
        """ Loads the FA elements describes in the TOML file found at `filepath`.

        Args:
            filepath: path to a TOML file

        Raises:
            KeyError: if unknown state is found as initial state / final state / next state
        """
        data: dict = None   # file content

        # load file content
        with open(filepath, 'rb') as file:
            data = tomllib.load(file)

        # init alphabet
        self.alphabet = data['alphabet']

        # init states
        for state in data['states']:
            name = state['name']
            self.states[name] = FiniteAutomata.State(name, {})

        # init transitions
        for state in data['states']:
            name = state['name']
            for transition in state['transitions']:
                symbol = transition['symbol']
                next_state = transition['next_state']

                # raise error if next_state does not belong to the list of FA's states
                if next_state not in self.states:
                    raise KeyError(f"Transition ({name}, {symbol}) has as next state {next_state}, but {next_state} was not found in the set of states!")

                # add the new transition
                self.states[name].transitions[symbol] = self.states[next_state]

        # init initial state
        self.initial_state = self.states[data['initial_state']]

        # init final states
        for final_state in data['final_states']:
            # raise error if final_state does not belong to the list of FA's states
            if final_state not in self.states:
                raise KeyError(f"Final state {final_state} was not found in the set of states!")

            # add the final state
            self.final_states.append(self.states[final_state])

    def check_acceptance(self, sequence: str) -> bool:
        """ Check if `sequence` is accepted by the FA.

        Args:
            sequence: a string

        Returns: True if `sequence` is accepted by FA else False
        """
        # set current state to be the initial state
        current_state = self.initial_state

        # iterate through the symbols of the sequence
        for symbol in sequence:
            # check if symbol is part of the FA's alphabet
            if symbol not in self.alphabet:
                return False

            # check if the current state has a transition that consumes the current symbol
            if symbol not in current_state.transitions:
                return False

            # perform transition
            current_state = current_state.transitions[symbol]

        # check if the current state is part of the FA's final states
        if current_state not in self.final_states:
            return False

        return True
