import tomllib


class Grammar:
    def __init__(self, filepath: str):
        """ Initializes grammar from `filepath`. """
        self.start: str = None                              # starting nonterminal
        self.terminals: list[str] = []                      # list of terminals
        self.nonterminals: list[str] = []                   # list of nonterminals
        self.productions: dict[str, list[list[str]]] = {}   # dictionary of nonterminal -> list of productions

        self._load(filepath)

    def _load(self, filepath: str) -> None:
        """ Loads grammar from `filepath`. """
        with open(filepath, 'rb') as file:
            data = tomllib.load(file)

        self.start = data['start']
        self.terminals = data['terminals']
        self.nonterminals = data['nonterminals']

        for rule in data['rules']:
            self.productions[rule['nonterminal']] = list(map(str.split, rule['productions']))

    def is_cfg(self) -> bool:
        """ Checks if grammar is context-free. """
        for nonterminal in self.productions:
            if nonterminal not in self.nonterminals or len(nonterminal.split()) != 1:
                return False
        return True
