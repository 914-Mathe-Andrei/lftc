from SymbolTable import *


def main():
    id_symtable = IdentifierSymbolTable()
    const_symtable = ConstSymbolTable()

    # identifier symbol table
    id_symtable.insert("x", Type.INT, 5)
    id_symtable.insert("y", Type.INT, None)
    id_symtable.insert("z", Type.STR, "foo")
    id_symtable.update("y", 10)
    assert id_symtable.get("y").value == 10
    assert id_symtable.contains("z")
    id_symtable.delete("z")
    assert not id_symtable.contains("z")

    # constants symbol table
    const_symtable.insert(5, Type.INT)
    const_symtable.insert("foo", Type.STR)
    assert const_symtable.get(5) == Const(5, Type.INT)
    assert const_symtable.contains("foo")
    const_symtable.delete("foo")
    assert not const_symtable.contains("foo")

    print(f"Identifiers symbol table:\n{id_symtable}")
    print()
    print(f"Constants symbol table:\n{const_symtable}")


if __name__ == '__main__':
    main()
