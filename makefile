
ANTLR = java -jar antlr-4.8-complete.jar

GENERATED_CODE = \
	CalamityLexer.py \
	CalamityLexer.tokens \
	CalamityParser.py \
	CalamityLexer.py \
	CalamityListener.py

TRIER_GENERATED_CODE = \
	trierLexer.py \
	trierLexer.tokens \
	trierParser.py \
	trierLexer.py \
	trierListener.py

CPP_GENERATED_CODE = \
	CalamityBaseListener.cpp \
	CalamityBaseListener.h \
	CalamityBaseVisitor.cpp \
	CalamityBaseVisitor.h \
	CalamityLexer.cpp \
	CalamityLexer.h \
	CalamityListener.cpp \
	CalamityListener.h \
	CalamityVisitor.cpp \
	CalamityVisitor.h \
	CalamityParser.cpp \
	CalamityParser.h


run: calam
	./calam programs/boolean-logic.cal


Environment.o: Environment.h Environment.cpp
	$(CPP) -c Environment.cpp

linenoise.o: linenoise/linenoise.cpp
	$(CPP) -c linenoise/linenoise.cpp

BigInteger.o: BigInteger.h BigInteger.cpp
	$(CPP) -c BigInteger.cpp

Code.o: Code.h Code.cpp
	$(CPP) -c Code.cpp

objects.o: objects.cpp objects.h
	$(CPP) -c objects.cpp

codetest: codetest.cpp objects.o Code.o Environment.o
	$(CPP) codetest.cpp objects.o Code.o Environment.o -o codetest

test: printtree.py $(GENERATED_CODE)
	python printtree.py

CalamityLexer.py: Calamity.g4
	$(ANTLR) -Dlanguage=Python2 Calamity.g4

CalamityLexer.tokens: Calamity.g4
	$(ANTLR) -Dlanguage=Python2 Calamity.g4

CalamityParser.py: Calamity.g4
	$(ANTLR) -Dlanguage=Python2 Calamity.g4

Calamity.tokens: Calamity.g4
	$(ANTLR) -Dlanguage=Python2 Calamity.g4

CalamityListener.py: Calamity.g4
	$(ANTLR) -Dlanguage=Python2 Calamity.g4


CalamityBaseListener.cpp: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp -visitor Calamity.g4

CalamityBaseListener.h: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp -visitor Calamity.g4

CalamityBaseVisitor.cpp: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp -visitor Calamity.g4

CalamityBaseVisitor.h: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp -visitor Calamity.g4

CalamityLexer.cpp: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp -visitor Calamity.g4

CalamityLexer.h: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp -visitor Calamity.g4

CalamityListener.cpp: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp -visitor Calamity.g4

CalamityListener.h: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp -visitor Calamity.g4

CalamityVisitor.cpp: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp -visitor Calamity.g4

CalamityVisitor.h: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp -visitor Calamity.g4

CalamityParser.cpp: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp -visitor Calamity.g4

CalamityParser.h: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp -visitor Calamity.g4


CPP = c++ -std=gnu++11 -g3

INCLUDES = \
	-Iantlr4-cpp-runtime-4.8-macos/antlr4-runtime \
	-Ilinenoise

ANTLR_LIBRARY = \
	antlr4-cpp-runtime-4.8-macos/lib/libantlr4-runtime.a

CalamityBaseListener.o: CalamityBaseListener.h CalamityBaseListener.cpp
	$(CPP) -c $(INCLUDES) CalamityBaseListener.cpp

CalamityBaseVisitor.o: CalamityBaseVisitor.h CalamityBaseVisitor.cpp
	$(CPP) -c $(INCLUDES) CalamityBaseVisitor.cpp

CalamityLexer.o: CalamityLexer.h CalamityLexer.cpp
	$(CPP) -c $(INCLUDES) CalamityLexer.cpp

CalamityListener.o: CalamityListener.h CalamityListener.cpp
	$(CPP) -c $(INCLUDES) CalamityListener.cpp

CalamityVisitor.o: CalamityVisitor.h CalamityVisitor.cpp
	$(CPP) -c $(INCLUDES) CalamityVisitor.cpp

CalamityParser.o: CalamityParser.h CalamityParser.cpp
	$(CPP) -c $(INCLUDES) CalamityParser.cpp

TreeShapeListener.o: TreeShapeListener.h TreeShapeListener.cpp
	$(CPP) -c $(INCLUDES) TreeShapeListener.cpp


CALAMITY_OBJETS = \
	Code.o \
	objects.o \
	BigInteger.o \
	Environment.o \
	CalamityBaseListener.o \
	CalamityLexer.o \
	CalamityListener.o \
	CalamityVisitor.o \
	CalamityParser.o \
	TreeShapeListener.o


calam: main.cpp $(CALAMITY_OBJETS)
	$(CPP) $(INCLUDES) \
	main.cpp -o calam \
	$(CALAMITY_OBJETS) \
	linenoise.o \
	$(ANTLR_LIBRARY)

try: printtree.py $(TRIER_GENERATED_CODE)
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
	rm -f $(TRIER_GENERATED_CODE)
	rm -f $(CPP_GENERATED_CODE)
	rm -f Calamity.interp
	rm -f Calamity.tokens
	rm -f *.pyc
	rm -f *.o
	rm -f calam
	rm -f *.interp
	rm -f *.tokens

