#include <iostream>


#include "myFloat.h"

int main()
{
    float a = 10.0;
    float b = 5.0;
    myFloat A(a);
    myFloat B(b);

    myFloat C = A/B;

/*    int i;

    if (C<A)
        i = 1;
    else
        i = 0; */

    std::cout << C.getValue() << std::endl;
    return 0;
}
