#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>

int main()
{
    pid_t i;
    printf("before fork\r\n");
    i = fork();
    printf("after fork: i = %d\r\n", i);

    return 0;
}