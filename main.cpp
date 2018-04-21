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

class Pair : public Line
{
public:
    Pair()
    {
    }

    Expression* left;
    Expression* right;

    virtual std::string toString() const override
    {
        return left->toString() + ":" + right->toString();
    }
};

class Reference : public Thing
{
};


class Assignment : public Line
{
public:
    Assignment()
    {
    }

    Reference* reference;
    std::string operation;
    Expression* expression;

    virtual std::string toString() const override
    {
        return reference->toString() + operation + expression->toString();
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

class Comparable : public Thing
{
public:
    Comparable()
    {
    }
};

class Logicable : public Thing
{
public:
    Logicable()
    {
    }
};

class Addable : public Thing
{
public:
    Addable()
    {
    }
};

class Multiplyable : public Thing
{
public:
    Multiplyable()
    {
    }
};

class Evaluable : public Thing
{
public:
    Evaluable()
    {
    }
};

class Call : public Thing
{
public:
    Evaluable* evaluable;
    std::vector<Expression*> expressions;

    virtual std::string toString() const override
    {
        std::string accum = evaluable->toString() + " ";
        for( std::vector<Expression*>::const_iterator itr = expressions.begin();
            itr != expressions.end(); itr++ )
        {
            accum += (*itr)->toString() + " ";
        }
        return accum;
    }
};

class AddedList : public Thing
{
public:
    AddedList()
    {
    }

    std::vector<Addable*> operands;
    std::vector<std::string> ops;

    virtual std::string toString() const override
    {
        std::string accum;
        size_t n = operands.size();

        for( size_t i = 0; i < n-1; i++ )
            accum += (operands[i])->toString() + ops[i];

        accum += operands[n-1]->toString();

        return accum;
    }
};

class Negative : public Thing
{
public:
    Negative()
    {
    }

    Addable* operand;

    virtual std::string toString() const override
    {
        return std::string("-") + operand->toString();
    }
};

class Product : public Thing
{
public:
    Product()
    {
    }

    std::vector<Multiplyable*> operands;
    std::vector<std::string> ops;

    virtual std::string toString() const override
    {
        std::string accum;
        size_t n = operands.size();

        for( size_t i = 0; i < n-1; i++ )
            accum += (operands[i])->toString() + ops[i];

        accum += operands[n-1]->toString();

        return accum;
    }
};

class Conjunction : public Thing
{
public:
    Conjunction()
    {
    }

    std::vector<Logicable*> operands;
    std::vector<std::string> ops;

    virtual std::string toString() const override
    {
        std::string accum;
        size_t n = operands.size();

        for( size_t i = 0; i < n-1; i++ )
            accum += (operands[i])->toString() + " " + ops[i] + " ";

        accum += operands[n-1]->toString();

        return accum;
    }
};

class Negation : public Thing
{
public:
    Negation()
    {
    }

    Logicable* operand;

    virtual std::string toString() const override
    {
        return std::string("not ") + operand->toString();
    }
};

class Comparison : public Logicable
{
private:
    Comparable* left;
    std::string op;
    Comparable* right;

public:
    Comparison(
        Comparable* left,
        std::string op,
        Comparable* right)
        : left(left)
        , op(op)
        , right(right)
    {
    }

    virtual std::string toString() const
    {
        return left->toString() + op + right->toString();
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

class Number : public Expression
{
private:
    double value;
public:

    Number()
        : value(0.0)
    {
    }

    Number(const std::string& text)
    {
        value = atof(text.c_str());
    }

    virtual std::string toString() const override
    {
        char buffer[1000];
        sprintf(buffer, "%f", value);
        return std::string(buffer);
    }
};

class Boolean : public Expression
{
private:
    bool value;
public:

    Boolean()
        : value(false)
    {
    }

    Boolean(const std::string& text)
    {
        value = (text == "true");
    }

    virtual std::string toString() const override
    {
        return std::string(value ? "true" : "false");
    }
};

class Word : public Expression
{
private:
    std::string name;
public:

    Word()
    {
    }

    Word(const std::string& text)
        : name(text)
    {
    }

    virtual std::string toString() const override
    {
        return name;
    }
};

class Member : public Expression
{
private:
    std::string name;
public:

    Member()
    {
    }

    Member(const std::string& text)
        : name(text.substr(1, text.size()-1))
    {
    }

    virtual std::string toString() const override
    {
        return std::string(".") + name;
    }
};


class String : public Expression
{
private:
    std::string value;
public:

    String()
    {
    }

    String(const std::string& text)
    {
        value = text.substr(1, text.size()-2);
    }

    virtual std::string toString() const override
    {
        return std::string("\"") + value + std::string("\"");
    }
};


class MainVisitor : public CalamityBaseVisitor
{
    virtual Any visitProgram(CalamityParser::ProgramContext* ctx) override
    {
        printf( "visiting program\n" );
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
        printf( "visiting line\n" );
        HType lineH = visit(ctx->children[0]);
        Line* lineptr = static_cast<Line*>(lineH.thing);
        return lineptr;
    }

    virtual Any visitAssignment(CalamityParser::AssignmentContext* ctx) override
    {
        Assignment* assignment = new Assignment;

        HType hRef = visit(ctx->children[0]);
        assignment->reference = static_cast<Reference*>(hRef.thing);
        assignment->operation = ctx->children[1]->getText();

        HType hExp = visit(ctx->children[2]);
        assignment->expression = static_cast<Expression*>(hExp.thing);

        return HType(assignment);
    }

    virtual Any visitPair(CalamityParser::PairContext* ctx) override
    {
        Pair* pair = new Pair;

        HType hLeft = visit(ctx->children[0]);
        HType hRight = visit(ctx->children[2]);

        pair->left = static_cast<Expression*>(hLeft.thing);
        pair->right = static_cast<Expression*>(hRight.thing);

        return HType(pair);
    }

    virtual Any visitExpression(CalamityParser::ExpressionContext* ctx) override
    {
        printf( "visiting expression %s\n", ctx->children[0]->getText().c_str() );
        return visit(ctx->children[0]);
    }

    virtual Any visitFunction(CalamityParser::FunctionContext* ctx) override
    {
        HType programH = visit(ctx->children[1]);
        return HType(new Function(static_cast<Program*>(programH.thing)));
    }

    virtual Any visitGroup(CalamityParser::GroupContext* ctx) override
    {
        printf( "visiting group\n" );
        HType programH = visit(ctx->children[1]);
        return HType(new Group(static_cast<Program*>(programH.thing)));
    }

    virtual Any visitComparable(CalamityParser::ComparableContext* ctx) override
    {
        return visit(ctx->children[0]);
    }

    virtual Any visitComparison(CalamityParser::ComparisonContext* ctx) override
    {
        HType leftH = visit(ctx->children[0]);
        HType rightH = visit(ctx->children[2]);

        Comparable* left = static_cast<Comparable*>(leftH.thing);
        Comparable* right = static_cast<Comparable*>(rightH.thing);

        return HType(new Comparison(left, ctx->children[1]->getText(), right));
    }

    virtual Any visitAddable(CalamityParser::AddableContext* ctx) override
    {
        printf("visiting addable\n");
        return visit(ctx->children[0]);
    }

    virtual Any visitNumber(CalamityParser::NumberContext* ctx) override
    {
        printf("visiting number\n");
        return HType(new Number(ctx->getText()));
    }

    virtual Any visitWord(CalamityParser::WordContext* ctx) override
    {
        printf("visiting word\n");
        return HType(new Word(ctx->getText()));
    }

    virtual Any visitMember(CalamityParser::MemberContext* ctx) override
    {
        printf("visiting member\n");
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

        printf("visiting added list\n");

        for( size_t i = 0; i < n; i++ )
        {
            if( i%2 )
            {
                addedList->ops.push_back( ctx->children[i]->getText() );
            }
            else
            {
                HType h = visit(ctx->children[i]);
                addedList->operands.push_back(static_cast<Addable*>(h.thing));
            }
        }

        return HType(addedList);
    }

    virtual Any visitProduct(CalamityParser::ProductContext* ctx) override
    {
        Product* product = new Product;

        size_t n = ctx->children.size();

        printf("visiting product\n");

        for( size_t i = 0; i < n; i++ )
        {
            if( i%2 )
            {
                product->ops.push_back( ctx->children[i]->getText() );
            }
            else
            {
                HType h = visit(ctx->children[i]);
                product->operands.push_back(static_cast<Multiplyable*>(h.thing));
            }
        }

        return HType(product);
    }

    virtual Any visitCall(CalamityParser::CallContext* ctx) override
    {
        printf("visiting call\n");
        Call* call = new Call;

        size_t n = ctx->children.size();

        HType h = visit(ctx->children[0]);
        call->evaluable = static_cast<Evaluable*>(h.thing);

        for (size_t i = 1; i < n; i++)
        {
            HType h = visit(ctx->children[i]);
            call->expressions.push_back(static_cast<Expression*>(h.thing));
        }

        return HType(call);
    }

    virtual Any visitNegative(CalamityParser::NegativeContext* ctx) override
    {
        Negative* negative = new Negative;
        HType h = visit(ctx->children[1]);
        negative->operand = static_cast<Addable*>(h.thing);
        return HType(negative);
    }

    virtual Any visitConjunction(CalamityParser::ConjunctionContext* ctx) override
    {
        Conjunction* conjunction = new Conjunction;

        size_t n = ctx->children.size();

        printf("visiting conjunction\n");

        for( size_t i = 0; i < n; i++ )
        {
            if( i%2 )
            {
                conjunction->ops.push_back( ctx->children[i]->getText() );
            }
            else
            {
                HType h = visit(ctx->children[i]);
                conjunction->operands.push_back(static_cast<Logicable*>(h.thing));
            }
        }

        return HType(conjunction);
    }

    virtual Any visitNegation(CalamityParser::NegationContext* ctx) override
    {
        Negation* negation = new Negation;
        HType h = visit(ctx->children[1]);
        negation->operand = static_cast<Logicable*>(h.thing);
        return HType(negation);
    }

    virtual Any visitBoolean(CalamityParser::BooleanContext* ctx) override
    {
        Boolean* boolean = new Boolean(ctx->getText());
        return HType(boolean);
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

