
#include "Code.h"

int main(int argc, char** args)
{
    Number a("3");
    Number b("4");

    AddedList l(&a);
    l.add("+", &b);

    printf( "%s\n", l.toString().c_str() );
    return 0;
}
