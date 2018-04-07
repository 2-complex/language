
GENERATED_CODE = \
	calamityLexer.py \
	calamityLexer.tokens \
	calamityParser.py \
	calamityLexer.py

test: printtree.py $(GENERATED_CODE)
	python printtree.py

calamityLexer.py: calamity.g4
	antlr -Dlanguage=Python2 calamity.g4

calamityLexer.tokens: calamity.g4
	antlr -Dlanguage=Python2 calamity.g4

calamityParser.py: calamity.g4
	antlr -Dlanguage=Python2 calamity.g4

calamity.tokens: calamity.g4
	antlr -Dlanguage=Python2 calamity.g4

