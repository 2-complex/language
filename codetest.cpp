
#include "Code.h"

void testAddSubtract()
{
    Environment env(new object::Object);

    code::Number a("3");
    code::Number b("4");

    code::AddedList sum(&a);
    sum.append("+", &b);

    printf( "%s = \n", sum.toString().c_str() );
    printf( "%s\n", sum.evaluate(env)->toString().c_str() );

    code::AddedList difference(&a);
    difference.append("-", &b);

    printf( "%s = \n", difference.toString().c_str() );
    printf( "%s\n", difference.evaluate(env)->toString().c_str() );

    code::Negative n(&a);

    printf( "%s = \n", n.toString().c_str() );
    printf( "%s\n", n.evaluate(env)->toString().c_str() );
}

void testBooeanOps()
{
    Environment env(new object::Object);

    code::Boolean codeTrue("true");
    code::Boolean codeFalse("false");

    code::Conjunction conjAnd(&codeTrue);
    conjAnd.append("and", &codeFalse);

    printf( "%s = \n", conjAnd.toString().c_str() );
    printf( "%s\n", conjAnd.evaluate(env)->toString().c_str() );


    code::Conjunction conjOr(&codeTrue);
    conjOr.append("or", &codeFalse);

    printf( "%s = \n", conjOr.toString().c_str() );
    printf( "%s\n", conjOr.evaluate(env)->toString().c_str() );


    code::Negation notTrue(&codeTrue);

    printf( "%s = \n", notTrue.toString().c_str() );
    printf( "%s\n", notTrue.evaluate(env)->toString().c_str() );
}

void testStringConcat()
{
    Environment env(new object::Object);

    code::String codeA("\"apples\"");
    code::String codeB("\"bananas\"");

    code::AddedList sum(&codeA);
    sum.append("+", &codeB);

    printf( "%s = \n", sum.toString().c_str() );
    printf( "%s\n", sum.evaluate(env)->toString().c_str() );
}

void testArrayConcat()
{
    Environment env(new object::Object);

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
    printf( "%s\n", sum.evaluate(env)->toString().c_str() );
}

void testAssignments()
{
    Environment env(new object::Object);

    code::Word x("x");
    code::Number three("3");
    code::Assignment codeA(&x, "=", &three);

    codeA.evaluate(env);

    printf( "%s = \n", x.toString().c_str() );
    printf( "%s\n", x.evaluate(env)->toString().c_str() );
}

int main(int argc, char** args)
{
    // testAddSubtract();
    // testBooeanOps();
    // testStringConcat();
    // testArrayConcat();
    testAssignments();

    return 0;
}

