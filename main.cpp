#include <iostream>

#include "TreeShapeListener.h"

#include "CalamityLexer.h"
#include "CalamityParser.h"
#include "CalamityBaseVisitor.h"

#include "antlr4-runtime.h"
#include <stdio.h>

using namespace antlrcpp;
using namespace antlr4;

class Thing
{
public:
    virtual std::string toString() const
    {
        return std::string(".");
    }
};

class HType
{
public:
    HType(Thing* thing)
        : thing(thing)
    {
    }

    Thing* thing;
};

class Line : public Thing
{
};

class Assignment : public Line
{
public:
    Assignment(
        const std::string& reference,
        const std::string& operation,
        const std::string& expression)
        : reference(reference)
        , operation(operation)
        , expression(expression)
    {
    }

    std::string reference;
    std::string operation;
    std::string expression;

    virtual std::string toString() const override
    {
        return reference + operation + expression;
    }
};

class Pair : public Line
{
public:
    Pair(
        const std::string& left,
        const std::string& right)
        : left(left)
        , right(right)
    {
    }

    std::string left;
    std::string right;

    virtual std::string toString() const override
    {
        return left + ":" + right;
    }
};

class Expression : public Line
{
public:
    Expression()
    {
    }

    Expression(
        const std::string& expression)
        : expression(expression)
    {
    }

    std::string expression;

    virtual std::string toString() const override
    {
        return expression;
    }
};

class Program : public Thing
{
public:
    std::vector<Line*> lines;

    virtual std::string toString() const override
    {
        std::string accum;
        for( std::vector<Line*>::const_iterator itr = lines.begin(); itr != lines.end(); itr++ )
        {
            accum += (*itr)->toString() + ",";
        }
        return accum;
    }
};

class Function : public Expression
{
private:
    Program* program;

public:
    Function(Program* program)
        : program(program)
    {
    }

    virtual std::string toString() const override
    {
        return std::string("{") + program->toString() + std::string("}");
    }
};

class Group : public Expression
{
private:
    Program* program;

public:
    Group(Program* program)
        : program(program)
    {
    }

    virtual std::string toString() const override
    {
        return std::string("(") + program->toString() + std::string(")");
    }
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
        Line* lineptr = static_cast<Line*>(lineH.thing);
        return lineptr;
    }

    virtual Any visitAssignment(CalamityParser::AssignmentContext* ctx) override
    {
        return HType(new Assignment(
            ctx->children[0]->getText(),
            ctx->children[1]->getText(),
            ctx->children[2]->getText()));
    }

    virtual Any visitPair(CalamityParser::PairContext* ctx) override
    {
        return HType(new Pair(
            ctx->children[0]->getText(),
            ctx->children[2]->getText()));
    }

    virtual Any visitExpression(CalamityParser::ExpressionContext* ctx) override
    {
        return visit(ctx->children[0]);
    }

    virtual Any visitFunction(CalamityParser::FunctionContext* ctx) override
    {
        HType programH = visit(ctx->children[1]);
        return HType(new Function(static_cast<Program*>(programH.thing)));
    }

    virtual Any visitGroup(CalamityParser::GroupContext* ctx) override
    {
        HType programH = visit(ctx->children[1]);
        return HType(new Group(static_cast<Program*>(programH.thing)));
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

    printf( "%s\n", a.thing->toString().c_str() );

    return 0;
}

