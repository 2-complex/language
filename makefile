
ANTLR = java -jar /usr/local/lib/antlr-4.7.1-complete.jar

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
	CalamityLexer.cpp \
	CalamityLexer.h \
	CalamityListener.cpp \
	CalamityListener.h \
	CalamityParser.cpp \
	CalamityParser.h


run: calam
	./calam


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
	$(ANTLR) -Dlanguage=Cpp Calamity.g4

CalamityBaseListener.h: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp Calamity.g4

CalamityLexer.cpp: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp Calamity.g4

CalamityLexer.h: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp Calamity.g4

CalamityListener.cpp: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp Calamity.g4

CalamityListener.h: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp Calamity.g4

CalamityParser.cpp: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp Calamity.g4

CalamityParser.h: Calamity.g4
	$(ANTLR) -Dlanguage=Cpp Calamity.g4

CPP = c++ -std=gnu++11

INCLUDES = \
	-Iantlr4-cpp-runtime-4.7.1-macos/antlr4-runtime

ANTLR_LIBRARY = \
	antlr4-cpp-runtime-4.7.1-macos/lib/libantlr4-runtime.a

CalamityBaseListener.o: CalamityBaseListener.h CalamityBaseListener.cpp
	$(CPP) -c $(INCLUDES) CalamityBaseListener.cpp

CalamityLexer.o: CalamityLexer.h CalamityLexer.cpp
	$(CPP) -c $(INCLUDES) CalamityLexer.cpp

CalamityListener.o: CalamityListener.h CalamityListener.cpp
	$(CPP) -c $(INCLUDES) CalamityListener.cpp

CalamityParser.o: CalamityParser.h CalamityParser.cpp
	$(CPP) -c $(INCLUDES) CalamityParser.cpp


CALAMITY_OBJETS = \
	CalamityBaseListener.o \
	CalamityLexer.o \
	CalamityListener.o \
	CalamityParser.o


calam: main.cpp $(CALAMITY_OBJETS)
	$(CPP) $(INCLUDES) \
	main.cpp -o calam \
	$(CALAMITY_OBJETS) \
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

