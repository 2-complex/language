#include <iostream>

#include "TreeShapeListener.h"
#include "Code.h"

#include "CalamityLexer.h"
#include "CalamityParser.h"
#include "CalamityBaseVisitor.h"

#include "antlr4-runtime.h"
#include <stdio.h>

using namespace antlrcpp;
using namespace antlr4;
using namespace code;

class HType
{
public:
    HType(Code* code)
        : code(code)
    {
    }

    Code* code;
};

class MainVisitor : public CalamityBaseVisitor
{
    virtual Any visitProgram(CalamityParser::ProgramContext* ctx) override
    {
        Program* program = new Program;

        size_t n = ctx->children.size();
        for (size_t i = 0; i < n; i+=2)
        {
            program->lines.push_back( visit(ctx->children[i]) );
        }

        return HType(program);
    }

    virtual Any visitLine(CalamityParser::LineContext* ctx) override
    {
        HType lineH = visit(ctx->children[0]);
        Line* lineptr = static_cast<Line*>(lineH.code);
        return lineptr;
    }

    virtual Any visitAssignment(CalamityParser::AssignmentContext* ctx) override
    {
        Assignment* assignment = new Assignment;

        HType hRef = visit(ctx->children[0]);
        assignment->reference = static_cast<Expression*>(hRef.code);
        assignment->operation = ctx->children[1]->getText();

        HType hExp = visit(ctx->children[2]);
        assignment->expression = static_cast<Expression*>(hExp.code);

        return HType(assignment);
    }

    virtual Any visitPair(CalamityParser::PairContext* ctx) override
    {
        Pair* pair = new Pair;

        HType hLeft = visit(ctx->children[0]);
        HType hRight = visit(ctx->children[2]);

        pair->left = static_cast<Expression*>(hLeft.code);
        pair->right = static_cast<Expression*>(hRight.code);

        return HType(pair);
    }

    virtual Any visitExpression(CalamityParser::ExpressionContext* ctx) override
    {
        return visit(ctx->children[0]);
    }

    virtual Any visitFunction(CalamityParser::FunctionContext* ctx) override
    {
        HType programH = visit(ctx->children[1]);
        return HType(new Function(static_cast<Program*>(programH.code)));
    }

    virtual Any visitGroup(CalamityParser::GroupContext* ctx) override
    {
        HType programH = visit(ctx->children[1]);
        return HType(new Group(static_cast<Program*>(programH.code)));
    }

    virtual Any visitComparable(CalamityParser::ComparableContext* ctx) override
    {
        return visit(ctx->children[0]);
    }

    virtual Any visitComparison(CalamityParser::ComparisonContext* ctx) override
    {
        HType leftH = visit(ctx->children[0]);
        HType rightH = visit(ctx->children[2]);

        Comparable* left = static_cast<Comparable*>(leftH.code);
        Comparable* right = static_cast<Comparable*>(rightH.code);

        return HType(new Comparison(left, ctx->children[1]->getText(), right));
    }

    virtual Any visitAddable(CalamityParser::AddableContext* ctx) override
    {
        return visit(ctx->children[0]);
    }

    virtual Any visitNumber(CalamityParser::NumberContext* ctx) override
    {
        return HType(new Number(ctx->getText()));
    }

    virtual Any visitWord(CalamityParser::WordContext* ctx) override
    {
        return HType(new Word(ctx->getText()));
    }

    virtual Any visitMember(CalamityParser::MemberContext* ctx) override
    {
        return HType(new Member(ctx->getText()));
    }

    virtual Any visitString(CalamityParser::StringContext* ctx) override
    {
        return HType(new String(ctx->getText()));
    }

    virtual Any visitAddedList(CalamityParser::AddedListContext* ctx) override
    {
        HType firstH = visit(ctx->children[0]);
        AddedList* addedList = new AddedList(static_cast<Addable*>(firstH.code));

        size_t n = ctx->children.size();
        for( size_t i = 1; i < n; i+=2 )
        {
            HType h = visit(ctx->children[i+1]);
            addedList->append( ctx->children[i]->getText(),
                 static_cast<Addable*>(h.code));
        }

        return HType(addedList);
    }

    virtual Any visitProduct(CalamityParser::ProductContext* ctx) override
    {
        HType firstH = visit(ctx->children[0]);
        Product* product = new Product(static_cast<Expression*>(firstH.code));

        size_t n = ctx->children.size();

        for( size_t i = 1; i < n; i+=2 )
        {
            HType h = visit(ctx->children[i+1]);
            product->append( ctx->children[i]->getText(),
                static_cast<Expression*>(static_cast<Expression*>(h.code)));
        }

        return HType(product);
    }

    virtual Any visitCall(CalamityParser::CallContext* ctx) override
    {
        Call* call = new Call;

        size_t n = ctx->children.size();

        for (size_t i = 0; i < n; i++)
        {
            HType h = visit(ctx->children[i]);
            call->expressions.push_back(static_cast<Expression*>(h.code));
        }

        return HType(call);
    }

    virtual Any visitNegative(CalamityParser::NegativeContext* ctx) override
    {
        Negative* negative = new Negative;
        HType h = visit(ctx->children[1]);
        negative->operand = static_cast<Addable*>(h.code);
        return HType(negative);
    }

    virtual Any visitConjunction(CalamityParser::ConjunctionContext* ctx) override
    {
        HType firstH = visit(ctx->children[0]);
        Conjunction* conjunction = new Conjunction(static_cast<Logicable*>(firstH.code));

        size_t n = ctx->children.size();
        for( size_t i = 1; i < n; i+=2 )
        {
            HType h = visit(ctx->children[i+1]);
            conjunction->append( ctx->children[i]->getText(),
                static_cast<Logicable*>(h.code));
        }

        return HType(conjunction);
    }

    virtual Any visitNegation(CalamityParser::NegationContext* ctx) override
    {
        HType h = visit(ctx->children[1]);
        return HType(new Negation(static_cast<Logicable*>(h.code)));
    }

    virtual Any visitBoolean(CalamityParser::BooleanContext* ctx) override
    {
        Boolean* boolean = new Boolean(ctx->getText());
        return HType(boolean);
    }

    virtual Any visitArray(CalamityParser::ArrayContext* ctx) override
    {
        Array* array = new Array;

        size_t n = ctx->children.size();
        for( size_t i = 1; i < n-1; i+=2 )
        {
            HType h = visit(ctx->children[i]);
            array->elements.push_back(static_cast<Expression*>(h.code));
        }

        return HType(array);
    }
};


void displayTreeShape(tree::ParseTree *tree)
{
    TreeShapeListener listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
}


#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linenoise.h"

int main(int argc, const char* argv[])
{
    std::ifstream stream;

    if(argc == 2)
    {
        stream.open(argv[1]);

        try
        {
            ANTLRInputStream input(stream);
            CalamityLexer lexer(&input);
            CommonTokenStream tokens(&lexer);
            CalamityParser parser(&tokens);

            tree::ParseTree* tree = parser.program();

            if( parser.getNumberOfSyntaxErrors() == 0 )
            {
                MainVisitor vistor;
                HType a = vistor.visit(tree);

                /*a.code*/
            }
        }
        catch(std::exception)
        {
            printf("PARSE ERROR\n\n");
        }

        return 0;
    }
    else if(argc == 1)
    {
        linenoiseHistoryLoad("history.txt");
        while(char* line = linenoise("> "))
        {
            std::stringstream ss(line);

            try
            {
                ANTLRInputStream input(ss);
                CalamityLexer lexer(&input);
                CommonTokenStream tokens(&lexer);
                CalamityParser parser(&tokens);

                tree::ParseTree* tree = parser.program();

                if( parser.getNumberOfSyntaxErrors() == 0 )
                {
                    MainVisitor vistor;
                    HType a = vistor.visit(tree);

                    std::shared_ptr<instruction::Procedure> procedure(new instruction::Procedure);
                    a.code->makeInstructions(*procedure);

                    printf( "procedure:\n%s", procedure->toString().c_str() );

                    instruction::Machine m(instruction::Location(procedure, 0));

                    while(m.step());

                    if( m.top() )
                    {
                        printf( "%s\n", m.top()->toString().c_str());
                    }

                    linenoiseHistoryAdd(line);
                    linenoiseHistorySave("history.txt");
                }
            }
            catch(std::exception& e)
            {
                printf("EXCEPTION CAUGHT AT TOP LEVEL %s\n\n", e.what());
                continue;
            }

            free(line);
        }
    }
}
