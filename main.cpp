#include <iostream>

#include "antlr4-runtime.h"
#include "CalamityLexer.h"
#include "CalamityParser.h"
#include "CalamityBaseListener.h"

#include <stdio.h>

using namespace antlrcpp;
using namespace antlr4;


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

    virtual void enterNumber(CalamityParser::NumberContext * /*ctx*/) override
    {
        printf( "%s%s\n", getIndentString().c_str(), "Number" );
        indentAmt++;
    }

    virtual void exitNumber(CalamityParser::NumberContext * /*ctx*/) override
    {
        indentAmt--;
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

    return 0;
}

