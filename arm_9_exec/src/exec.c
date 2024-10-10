#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    pid_t result;
    result = fork();
    if (result > 0)
    {   //替换父进程程序
        execl("/bin/ls", "ls", "-l", NULL);
        printf("error !\n");
        return -1;
    }


    return 0;
}