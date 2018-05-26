
#include "Code.h"

void testAddSubtract()
{
    code::Number a("3");
    code::Number b("4");

    code::AddedList sum(&a);
    sum.append("+", &b);

    printf( "%s = \n", sum.toString().c_str() );
    printf( "%s\n", sum.evaluate()->toString().c_str() );

    code::AddedList difference(&a);
    difference.append("-", &b);

    printf( "%s = \n", difference.toString().c_str() );
    printf( "%s\n", difference.evaluate()->toString().c_str() );
}

void testBooeanOps()
{
    code::Boolean codeTrue("true");
    code::Boolean codeFalse("false");

    code::Conjunction conjAnd(&codeTrue);
    conjAnd.append("and", &codeFalse);

    printf( "%s = \n", conjAnd.toString().c_str() );
    printf( "%s\n", conjAnd.evaluate()->toString().c_str() );


    code::Conjunction conjOr(&codeTrue);
    conjOr.append("or", &codeFalse);

    printf( "%s = \n", conjOr.toString().c_str() );
    printf( "%s\n", conjOr.evaluate()->toString().c_str() );
}

void testStringConcat()
{
    code::String codeA("\"apples\"");
    code::String codeB("\"bananas\"");

    code::AddedList sum(&codeA);
    sum.append("+", &codeB);

    printf( "%s = \n", sum.toString().c_str() );
    printf( "%s\n", sum.evaluate()->toString().c_str() );
}

void testArrayConcat()
{
    code::Array A;
    code::Array B;

    code::Number a("1");
    code::Number b("2");

    code::Number c("3");
    code::Number d("4");

    A.elements.push_back(&a);
    A.elements.push_back(&b);

    B.elements.push_back(&c);
    B.elements.push_back(&d);

    code::AddedList sum(&A);
    sum.append("+", &B);

    printf( "%s = \n", sum.toString().c_str() );
    printf( "%s\n", sum.evaluate()->toString().c_str() );
}

int main(int argc, char** args)
{
    // testAddSubtract();
    // testBooeanOps();
    // testStringConcat();

    testArrayConcat();
    return 0;
}

