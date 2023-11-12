import tomllib
from dataclasses import dataclass

from src.adt.buffer import ImmutableBuffer
from src.errors import InvalidSequence, InvalidSymbol

from typing import Generator


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

    def check_acceptance(self, buffer: ImmutableBuffer) -> Generator[str, None, None]:
        """ Check if there is a sequence in the buffer that is accepted by the FA.

        It will yield the current found symbol if the sequence found until at that moment is temporary accepted.

        Args:
            buffer (ImmutableBuffer): the buffer of characters

        Yields: current symbol

        Raises:
            InvalidSymbol: if invalid symbol found but sequence found until that moment is accepted
            InvalidSequence: if invalid symbol / no transition found or all buffer's characters consumed and sequence found is not accepted
        """
        # set current state to be the initial state
        current_state = self.initial_state

        # try to consume the symbols from the buffer
        while symbol := buffer.get(1):
            # check if symbol is part of the FA's alphabet
            if symbol not in self.alphabet:
                buffer.put(1)
                # raise InvalidSequence if found sequence until now is not accepted
                if current_state not in self.final_states:
                    raise InvalidSequence(f"Sequence found is rejected!", buffer.line, buffer.col)
                raise InvalidSymbol(f"Invalid symbol {symbol} found!", symbol, buffer.line, buffer.col)

            # check if the current state has a transition that consumes the current symbol
            if symbol not in current_state.transitions:
                buffer.put(1)
                raise InvalidSequence(f"Sequence found is rejected!", buffer.line, buffer.col)

            # perform transition
            current_state = current_state.transitions[symbol]

            # yield current symbol
            yield symbol

        # raise InvalidSequence if found sequence until now is not accepted
        if current_state not in self.final_states:
            buffer.put(1)
            raise InvalidSequence(f"Sequence found is rejected!", buffer.line, buffer.col)