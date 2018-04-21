
#include "CalamityBaseListener.h"
#include "CalamityParser.h"

#include <string>

#ifndef _TreeShapeListener_
#define _TreeShapeListener_

class TreeShapeListener : public CalamityBaseListener
{
public:
    TreeShapeListener();

    virtual void enterProgram(CalamityParser::ProgramContext * /*ctx*/) override;
    virtual void exitProgram(CalamityParser::ProgramContext * /*ctx*/) override;
    virtual void enterLine(CalamityParser::LineContext * /*ctx*/) override;
    virtual void exitLine(CalamityParser::LineContext * /*ctx*/) override;
    virtual void enterFunction(CalamityParser::FunctionContext * /*ctx*/) override;
    virtual void exitFunction(CalamityParser::FunctionContext * /*ctx*/) override;
    virtual void enterGroup(CalamityParser::GroupContext * /*ctx*/) override;
    virtual void exitGroup(CalamityParser::GroupContext * /*ctx*/) override;
    virtual void enterComparison(CalamityParser::ComparisonContext * /*ctx*/) override;
    virtual void exitComparison(CalamityParser::ComparisonContext * /*ctx*/) override;
    virtual void enterComparable(CalamityParser::ComparableContext * /*ctx*/) override;
    virtual void exitComparable(CalamityParser::ComparableContext * /*ctx*/) override;
    virtual void enterLogicable(CalamityParser::LogicableContext * /*ctx*/) override;
    virtual void exitLogicable(CalamityParser::LogicableContext * /*ctx*/) override;
    virtual void enterNegation(CalamityParser::NegationContext * /*ctx*/) override;
    virtual void exitNegation(CalamityParser::NegationContext * /*ctx*/) override;
    virtual void enterConjunction(CalamityParser::ConjunctionContext * /*ctx*/) override;
    virtual void exitConjunction(CalamityParser::ConjunctionContext * /*ctx*/) override;
    virtual void enterNegative(CalamityParser::NegativeContext * /*ctx*/) override;
    virtual void exitNegative(CalamityParser::NegativeContext * /*ctx*/) override;
    virtual void enterAddedList(CalamityParser::AddedListContext * /*ctx*/) override;
    virtual void exitAddedList(CalamityParser::AddedListContext * /*ctx*/) override;
    virtual void enterProduct(CalamityParser::ProductContext * /*ctx*/) override;
    virtual void exitProduct(CalamityParser::ProductContext * /*ctx*/) override;
    virtual void enterAddable(CalamityParser::AddableContext * /*ctx*/) override;
    virtual void exitAddable(CalamityParser::AddableContext * /*ctx*/) override;
    virtual void enterMutliplyable(CalamityParser::MutliplyableContext * /*ctx*/) override;
    virtual void exitMutliplyable(CalamityParser::MutliplyableContext * /*ctx*/) override;
    virtual void enterEvaluable(CalamityParser::EvaluableContext * /*ctx*/) override;
    virtual void exitEvaluable(CalamityParser::EvaluableContext * /*ctx*/) override;
    virtual void enterExpression(CalamityParser::ExpressionContext * /*ctx*/) override;
    virtual void exitExpression(CalamityParser::ExpressionContext * /*ctx*/) override;
    virtual void enterCall(CalamityParser::CallContext * /*ctx*/) override;
    virtual void exitCall(CalamityParser::CallContext * /*ctx*/) override;
    virtual void enterPair(CalamityParser::PairContext * /*ctx*/) override;
    virtual void exitPair(CalamityParser::PairContext * /*ctx*/) override;
    virtual void enterReference(CalamityParser::ReferenceContext * /*ctx*/) override;
    virtual void exitReference(CalamityParser::ReferenceContext * /*ctx*/) override;
    virtual void enterAssignment(CalamityParser::AssignmentContext * /*ctx*/) override;
    virtual void exitAssignment(CalamityParser::AssignmentContext * /*ctx*/) override;
    virtual void enterArray(CalamityParser::ArrayContext * /*ctx*/) override;
    virtual void exitArray(CalamityParser::ArrayContext * /*ctx*/) override;
    virtual void enterMember(CalamityParser::MemberContext * /*ctx*/) override;
    virtual void exitMember(CalamityParser::MemberContext * /*ctx*/) override;
    virtual void enterWord(CalamityParser::WordContext * /*ctx*/) override;
    virtual void exitWord(CalamityParser::WordContext * /*ctx*/) override;
    virtual void enterString(CalamityParser::StringContext * /*ctx*/) override;
    virtual void exitString(CalamityParser::StringContext * /*ctx*/) override;
    virtual void enterNumber(CalamityParser::NumberContext* ctx) override;
    virtual void exitNumber(CalamityParser::NumberContext * /*ctx*/) override;
    virtual void enterBoolean(CalamityParser::BooleanContext* ctx) override;
    virtual void exitBoolean(CalamityParser::BooleanContext * /*ctx*/) override;

private:
    int indentAmt;
    std::string getIndentString() const;
};

#endif

