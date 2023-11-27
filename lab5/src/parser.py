from dataclasses import dataclass
from src.structures.grammar import Grammar


@dataclass
class Item:
    nonterminal: str
    production: list[str]
    current_symbol_idx: int

    def __str__(self):
        result = f"{self.nonterminal} -> "
        for idx, symbol in enumerate(self.production):
            if idx == self.current_symbol_idx:
                result += '.'
            result += symbol
            if idx < len(self.production) - 1:
                result += ' '
        if self.current_symbol_idx == len(self.production):
            result += '.'
        return result


@dataclass
class State:
    closure: list[Item]


def _augment_grammar(grammar: Grammar) -> Grammar:
    grammar.nonterminals.append('S\'')
    grammar.productions['S\''] = [[grammar.start]]
    grammar.start = 'S\''
    return grammar


def _get_closure(initial_item: Item, grammar: Grammar) -> list[Item]:
    closure = [initial_item]
    while True:
        was_modified = False

        for item in closure:
            if item.current_symbol_idx >= len(item.production):
                continue

            symbol = item.production[item.current_symbol_idx]
            if symbol not in grammar.nonterminals:
                continue

            for production in grammar.productions[symbol]:
                temp_item = Item(symbol, production, 0)
                if temp_item not in closure:
                    was_modified = True
                    closure.append(temp_item)

        if not was_modified:
            break

    return closure


def _goto(state: State, symbol: str, grammar: Grammar) -> None | State:
    new_closure = []

    for item in state.closure:
        if item.current_symbol_idx >= len(item.production):
            continue
        if item.production[item.current_symbol_idx] != symbol:
            continue

        new_item = Item(item.nonterminal, item.production, item.current_symbol_idx + 1)

        for elem in _get_closure(new_item, grammar):
            if elem not in new_closure:
                new_closure.append(elem)

    if len(new_closure) == 0:
        return None
    return State(new_closure)


def _get_canonical_collection(grammar: Grammar) -> list[State]:
    item = Item(grammar.start, grammar.productions[grammar.start][0], 0)
    state0 = State(_get_closure(item, grammar))
    canonical_collection = [state0]

    while True:
        was_modified = False

        for state in canonical_collection:
            for symbol in grammar.terminals + grammar.nonterminals:
                temp_state = _goto(state, symbol, grammar)
                if temp_state is not None and temp_state not in canonical_collection:
                    was_modified = True
                    canonical_collection.append(temp_state)

        if not was_modified:
            break

    return canonical_collection


def parse(syntax_path: str):
    grammar = Grammar(syntax_path)
    grammar = _augment_grammar(grammar)
    canonical_collection = _get_canonical_collection(grammar)

    # print canonical collection to see if it works :)
    for state in canonical_collection:
        items_str = []
        for item in state.closure:
            items_str.append(str(item))
        print(items_str)
