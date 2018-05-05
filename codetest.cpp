
#include "Code.h"

int main(int argc, char** args)
{
    code::Number a("3");
    code::Number b("4");

    code::AddedList sum(&a);
    sum.append("+", &b);

    printf( "%s\n", sum.toString().c_str() );
    printf( "%s\n", sum.evaluate()->toString().c_str() );

    code::AddedList difference(&a);
    difference.append("-", &b);

    printf( "%s\n", difference.toString().c_str() );
    printf( "%s\n", difference.evaluate()->toString().c_str() );

    return 0;
}
