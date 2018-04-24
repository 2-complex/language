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



class HType
{
public:
    HType(Code* Code)
        : Code(Code)
    {
    }

    Code* Code;
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
        Line* lineptr = static_cast<Line*>(lineH.Code);
        return lineptr;
    }

    virtual Any visitAssignment(CalamityParser::AssignmentContext* ctx) override
    {
        Assignment* assignment = new Assignment;

        HType hRef = visit(ctx->children[0]);
        assignment->reference = static_cast<Reference*>(hRef.Code);
        assignment->operation = ctx->children[1]->getText();

        HType hExp = visit(ctx->children[2]);
        assignment->expression = static_cast<Expression*>(hExp.Code);

        return HType(assignment);
    }

    virtual Any visitPair(CalamityParser::PairContext* ctx) override
    {
        Pair* pair = new Pair;

        HType hLeft = visit(ctx->children[0]);
        HType hRight = visit(ctx->children[2]);

        pair->left = static_cast<Expression*>(hLeft.Code);
        pair->right = static_cast<Expression*>(hRight.Code);

        return HType(pair);
    }

    virtual Any visitExpression(CalamityParser::ExpressionContext* ctx) override
    {
        return visit(ctx->children[0]);
    }

    virtual Any visitFunction(CalamityParser::FunctionContext* ctx) override
    {
        HType programH = visit(ctx->children[1]);
        return HType(new Function(static_cast<Program*>(programH.Code)));
    }

    virtual Any visitGroup(CalamityParser::GroupContext* ctx) override
    {
        HType programH = visit(ctx->children[1]);
        return HType(new Group(static_cast<Program*>(programH.Code)));
    }

    virtual Any visitComparable(CalamityParser::ComparableContext* ctx) override
    {
        return visit(ctx->children[0]);
    }

    virtual Any visitComparison(CalamityParser::ComparisonContext* ctx) override
    {
        HType leftH = visit(ctx->children[0]);
        HType rightH = visit(ctx->children[2]);

        Comparable* left = static_cast<Comparable*>(leftH.Code);
        Comparable* right = static_cast<Comparable*>(rightH.Code);

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
        AddedList* addedList = new AddedList;

        size_t n = ctx->children.size();

        for( size_t i = 0; i < n; i++ )
        {
            if( i%2 )
            {
                addedList->ops.push_back( ctx->children[i]->getText() );
            }
            else
            {
                HType h = visit(ctx->children[i]);
                addedList->operands.push_back(static_cast<Addable*>(h.Code));
            }
        }

        return HType(addedList);
    }

    virtual Any visitProduct(CalamityParser::ProductContext* ctx) override
    {
        Product* product = new Product;

        size_t n = ctx->children.size();

        for( size_t i = 0; i < n; i++ )
        {
            if( i%2 )
            {
                product->ops.push_back( ctx->children[i]->getText() );
            }
            else
            {
                HType h = visit(ctx->children[i]);
                product->operands.push_back(static_cast<Multiplyable*>(h.Code));
            }
        }

        return HType(product);
    }

    virtual Any visitCall(CalamityParser::CallContext* ctx) override
    {
        Call* call = new Call;

        size_t n = ctx->children.size();

        HType h = visit(ctx->children[0]);
        call->evaluable = static_cast<Evaluable*>(h.Code);

        for( size_t i = 1; i < n; i++ )
        {
            HType h = visit(ctx->children[i]);
            call->expressions.push_back(static_cast<Expression*>(h.Code));
        }

        return HType(call);
    }

    virtual Any visitNegative(CalamityParser::NegativeContext* ctx) override
    {
        Negative* negative = new Negative;
        HType h = visit(ctx->children[1]);
        negative->operand = static_cast<Addable*>(h.Code);
        return HType(negative);
    }

    virtual Any visitArray(CalamityParser::ArrayContext* ctx) override
    {
        Array* array = new Array;

        for( size_t i = 1; i < n-1; i+=2 )
        {
            HType h = visit(ctx->children[i]);
            array->elements.push_back(static_cast<Expression*>(h.Code));
        }

        return HType(array);
    }
};


void displayTreeShape(tree::ParseTree *tree)
{
    TreeShapeListener listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
}


int main(int argc, const char* argv[])
{
    std::ifstream stream;
    stream.open(argv[1]);

    ANTLRInputStream input(stream);
    CalamityLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CalamityParser parser(&tokens);

    tree::ParseTree *tree = parser.program();
    displayTreeShape(tree);

    MainVisitor vistor;
    HType a = vistor.visit(tree);

    printf( "%s\n", a.Code->toString().c_str() );

    return 0;
}

