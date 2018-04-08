#include <iostream>

#include "antlr4-runtime.h"
#include "CalamityLexer.h"
#include "CalamityParser.h"
#include "CalamityBaseListener.h"
#include "CalamityBaseVisitor.h"

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

class Function : public Thing
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
        return std::string("{") + "I'm a function" + std::string("}");
    }
};



class TreeShapeListener : public CalamityBaseListener
{
    int indentAmt;

    std::string getIndentString()
    {
        std::string s;
        for(int i = 0; i < indentAmt; i++)
        {
            s += "  ";
        }
        return s;
    }

public:

    TreeShapeListener()
        : indentAmt(0)
    {
    }

    virtual void enterProgram(CalamityParser::ProgramContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Program" );
        indentAmt++;
    }

    virtual void exitProgram(CalamityParser::ProgramContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterLine(CalamityParser::LineContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Line" );
        indentAmt++;
    }

    virtual void exitLine(CalamityParser::LineContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterFunction(CalamityParser::FunctionContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Function" );
        indentAmt++;
    }

    virtual void exitFunction(CalamityParser::FunctionContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterGroup(CalamityParser::GroupContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Group" );
        indentAmt++;
    }

    virtual void exitGroup(CalamityParser::GroupContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterComparison(CalamityParser::ComparisonContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Comparison" );
        indentAmt++;
    }

    virtual void exitComparison(CalamityParser::ComparisonContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterComparable(CalamityParser::ComparableContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Comparable" );
        indentAmt++;
    }

    virtual void exitComparable(CalamityParser::ComparableContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterLogicable(CalamityParser::LogicableContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Logicable" );
        indentAmt++;
    }

    virtual void exitLogicable(CalamityParser::LogicableContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterNegation(CalamityParser::NegationContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Negation" );
        indentAmt++;
    }

    virtual void exitNegation(CalamityParser::NegationContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterConjunction(CalamityParser::ConjunctionContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Conjunction" );
        indentAmt++;
    }

    virtual void exitConjunction(CalamityParser::ConjunctionContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterNegative(CalamityParser::NegativeContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Negative" );
        indentAmt++;
    }

    virtual void exitNegative(CalamityParser::NegativeContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterAddedList(CalamityParser::AddedListContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "AddedList" );
        indentAmt++;
    }

    virtual void exitAddedList(CalamityParser::AddedListContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterProduct(CalamityParser::ProductContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Product" );
        indentAmt++;
    }

    virtual void exitProduct(CalamityParser::ProductContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterAddable(CalamityParser::AddableContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Addable" );
        indentAmt++;
    }

    virtual void exitAddable(CalamityParser::AddableContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterMutliplyable(CalamityParser::MutliplyableContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Mutliplyable" );
        indentAmt++;
    }

    virtual void exitMutliplyable(CalamityParser::MutliplyableContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterEvaluable(CalamityParser::EvaluableContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Evaluable" );
        indentAmt++;
    }

    virtual void exitEvaluable(CalamityParser::EvaluableContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterExpression(CalamityParser::ExpressionContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Expression" );
        indentAmt++;
    }

    virtual void exitExpression(CalamityParser::ExpressionContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterCall(CalamityParser::CallContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Call" );
        indentAmt++;
    }

    virtual void exitCall(CalamityParser::CallContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterPair(CalamityParser::PairContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Pair" );
        indentAmt++;
    }

    virtual void exitPair(CalamityParser::PairContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterReference(CalamityParser::ReferenceContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Reference" );
        indentAmt++;
    }

    virtual void exitReference(CalamityParser::ReferenceContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterAssignment(CalamityParser::AssignmentContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Assignment" );
        indentAmt++;
    }

    virtual void exitAssignment(CalamityParser::AssignmentContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterArray(CalamityParser::ArrayContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Array" );
        indentAmt++;
    }

    virtual void exitArray(CalamityParser::ArrayContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterMember(CalamityParser::MemberContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Member" );
        indentAmt++;
    }

    virtual void exitMember(CalamityParser::MemberContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterWord(CalamityParser::WordContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Word" );
        indentAmt++;
    }

    virtual void exitWord(CalamityParser::WordContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterString(CalamityParser::StringContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "String" );
        indentAmt++;
    }

    virtual void exitString(CalamityParser::StringContext * /*ctx*/) override
    {
        indentAmt--;
    }

    virtual void enterNumber(CalamityParser::NumberContext* ctx) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Number" );
        indentAmt++;
    }

    virtual void exitNumber(CalamityParser::NumberContext * /*ctx*/) override
    {
        indentAmt--;
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
        return HType(new Expression( ctx->children[0]->getText()));
    }

    virtual Any visitFunction(CalamityParser::FunctionContext* ctx) override
    {
        HType programH = visit(ctx->children[1]);
        return HType(new Function(static_cast<Program*>(programH.thing)));
    }

};


int main(int argc, const char* argv[])
{
    std::ifstream stream;
    stream.open(argv[1]);

    ANTLRInputStream input(stream);
    CalamityLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CalamityParser parser(&tokens);

    tree::ParseTree *tree = parser.program();

    TreeShapeListener listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

    MainVisitor vistor;
    HType a = vistor.visit(tree);

    printf( "%s\n", a.thing->toString().c_str() );

    return 0;
}

