
#include "TreeShapeListener.h"

std::string TreeShapeListener::getIndentString() const
{
    std::string s;
    for(int i = 0; i < indentAmt; i++)
    {
        s += "  ";
    }
    return s;
}

TreeShapeListener::TreeShapeListener()
    : indentAmt(0)
{
}

void TreeShapeListener::enterProgram(CalamityParser::ProgramContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Program", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitProgram(CalamityParser::ProgramContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterLine(CalamityParser::LineContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Line", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitLine(CalamityParser::LineContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterFunction(CalamityParser::FunctionContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Function", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitFunction(CalamityParser::FunctionContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterGroup(CalamityParser::GroupContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Group", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitGroup(CalamityParser::GroupContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterComparison(CalamityParser::ComparisonContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Comparison", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitComparison(CalamityParser::ComparisonContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterComparable(CalamityParser::ComparableContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Comparable", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitComparable(CalamityParser::ComparableContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterLogicable(CalamityParser::LogicableContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Logicable", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitLogicable(CalamityParser::LogicableContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterNegation(CalamityParser::NegationContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Negation", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitNegation(CalamityParser::NegationContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterConjunction(CalamityParser::ConjunctionContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Conjunction", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitConjunction(CalamityParser::ConjunctionContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterNegative(CalamityParser::NegativeContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Negative", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitNegative(CalamityParser::NegativeContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterAddedList(CalamityParser::AddedListContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "AddedList", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitAddedList(CalamityParser::AddedListContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterProduct(CalamityParser::ProductContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Product", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitProduct(CalamityParser::ProductContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterAddable(CalamityParser::AddableContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Addable", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitAddable(CalamityParser::AddableContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterMutliplyable(CalamityParser::MutliplyableContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Mutliplyable", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitMutliplyable(CalamityParser::MutliplyableContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterEvaluable(CalamityParser::EvaluableContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Evaluable", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitEvaluable(CalamityParser::EvaluableContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterExpression(CalamityParser::ExpressionContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Expression", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitExpression(CalamityParser::ExpressionContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterImpart(CalamityParser::ImpartContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Impart", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitImpart(CalamityParser::ImpartContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterCall(CalamityParser::CallContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Call", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitCall(CalamityParser::CallContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterPair(CalamityParser::PairContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Pair", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitPair(CalamityParser::PairContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterReference(CalamityParser::ReferenceContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Reference", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitReference(CalamityParser::ReferenceContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterAssignment(CalamityParser::AssignmentContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Assignment", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitAssignment(CalamityParser::AssignmentContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterArray(CalamityParser::ArrayContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Array", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitArray(CalamityParser::ArrayContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterMember(CalamityParser::MemberContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Member", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitMember(CalamityParser::MemberContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterWord(CalamityParser::WordContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Word", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitWord(CalamityParser::WordContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterString(CalamityParser::StringContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "String", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitString(CalamityParser::StringContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterNumber(CalamityParser::NumberContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Number", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitNumber(CalamityParser::NumberContext* ctx)
{
    indentAmt--;
}

void TreeShapeListener::enterBoolean(CalamityParser::BooleanContext* ctx)
{
    printf( "%s%s      %s\n", getIndentString().c_str(), "Boolean", ctx->getText().c_str() );
    indentAmt++;
}

void TreeShapeListener::exitBoolean(CalamityParser::BooleanContext* ctx)
{
    indentAmt--;
}
