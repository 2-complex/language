
import readline

languageName = "calamity"

Lexer = getattr(__import__(languageName + "Lexer"), languageName + "Lexer")
Parser = getattr(__import__(languageName + "Parser"), languageName + "Parser")
Listener = getattr(__import__(languageName + "Listener"), languageName + "Listener")

import antlr4
import sys


def evaluate(expr):
    def helper(expr, indent=''):
        for child in expr.getChildren():
            if isinstance(child, antlr4.tree.Tree.TerminalNode):
                print indent + child.getText()
            else:
                context_type_name = type(child).__name__[:-7]
                print indent + child.getText(), context_type_name
                helper(child, '  ' + indent)
    return helper(expr, '')


def main():
    while True:
        text = raw_input('> ')
        lexer = Lexer(antlr4.InputStream(text))
        stream = antlr4.CommonTokenStream(lexer)
        parser = Parser(stream)
        tree = parser.program()
        evaluate(tree)
if __name__ == '__main__':
    main()

