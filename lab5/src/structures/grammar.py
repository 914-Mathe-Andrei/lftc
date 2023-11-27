import tomllib


class Grammar:
    def __init__(self, filepath: str):
        self.start: str = None
        self.terminals: list[str] = []
        self.nonterminals: list[str] = []
        self.productions: dict[str, list[list[str]]] = {}

        self._load(filepath)

    def _load(self, filepath: str) -> None:
        with open(filepath, 'rb') as file:
            data = tomllib.load(file)

        self.start = data['start']
        self.terminals = data['terminals']
        self.nonterminals = data['nonterminals']

        for rule in data['rules']:
            self.productions[rule['nonterminal']] = list(map(str.split, rule['productions']))

    def is_cfg(self) -> bool:
        for nonterminal in self.productions:
            if nonterminal not in self.nonterminals or len(nonterminal.split()) != 1:
                return False
        return True
