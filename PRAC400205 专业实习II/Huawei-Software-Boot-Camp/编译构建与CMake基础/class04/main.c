#include <stdio.h>
#include "func1.h"
#include "func2.h"
#include "func3.h"

int main(void)
{
    printf("call main.\n");
    func1();
    func2();
    func3();
    return 0;
}
