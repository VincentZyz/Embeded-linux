#include<stdio.h>
#include "out.h"
#include "use.h"

int main()
{
    out();
    int ret_num = 0;
    ret_num = ret(10);
    printf("ret_num: %d\n", ret_num);
    put_out();

    return 0;
}