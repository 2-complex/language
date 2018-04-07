
ANTLR = java -jar /usr/local/lib/antlr-4.7.1-complete.jar

GENERATED_CODE = \
	calamityLexer.py \
	calamityLexer.tokens \
	calamityParser.py \
	calamityLexer.py \
	trierLexer.py \
	trierLexer.tokens \
	trierParser.py \
	trierLexer.py

test: printtree.py $(GENERATED_CODE)
	python printtree.py

calamityLexer.py: calamity.g4
	$(ANTLR) -Dlanguage=Python2 calamity.g4

calamityLexer.tokens: calamity.g4
	$(ANTLR) -Dlanguage=Python2 calamity.g4

calamityParser.py: calamity.g4
	$(ANTLR) -Dlanguage=Python2 calamity.g4

calamity.tokens: calamity.g4
	$(ANTLR) -Dlanguage=Python2 calamity.g4


try: printtree.py $(GENERATED_CODE)
	python printtree.py

trierLexer.py: trier.g4
	$(ANTLR) -Dlanguage=Python2 trier.g4

trierLexer.tokens: trier.g4
	$(ANTLR) -Dlanguage=Python2 trier.g4

trierParser.py: trier.g4
	$(ANTLR) -Dlanguage=Python2 trier.g4

trier.tokens: trier.g4
	$(ANTLR) -Dlanguage=Python2 trier.g4


clean:
	rm -f $(GENERATED_CODE)
