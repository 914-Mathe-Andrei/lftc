from src.structures.pif import ProgramInternalForm
from src.structures.symtable import IdSymTable, LiteralSymTable


class Program:
    def __init__(self):
        self.id_symtable: IdSymTable = IdSymTable()
        self.literal_symtable: LiteralSymTable = LiteralSymTable()
        self.pif: ProgramInternalForm = ProgramInternalForm()
