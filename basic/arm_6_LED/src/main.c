#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

//ARM开发板设备路径
#define RLED_DEV_PATH "/sys/class/leds/red/brightness"
#define BLED_DEV_PATH "/sys/class/leds/blue/brightness"
#define GLED_DEV_PATH "/sys/class/leds/green/brightness"

int main()
{
    int res = 0;
    int r_fd, b_fd, g_fd;
    printf("This is Led demo\n");

    //获取红灯设备文件描述符
    r_fd = open(RLED_DEV_PATH, O_WRONLY);
    if (r_fd < 0)
    {
        printf("Fail to open %s device\n", RLED_DEV_PATH);
        exit(1);
    }
    //获取蓝灯设备文件描述符
    b_fd = open(BLED_DEV_PATH, O_WRONLY);
    if (b_fd < 0)
    {
        printf("Fail to open %s device\n", BLED_DEV_PATH);
        exit(1);
    }
    //获取绿灯设备文件描述符
    g_fd = open(GLED_DEV_PATH, O_WRONLY);
    if (g_fd < 0)
    {
        printf("Fail to open %s device\n", GLED_DEV_PATH);
        exit(1);
    }
    
    while (1)
    {
        //红灯
        write(r_fd, "255", 3);
        //延时1秒
        sleep(1);
        write(r_fd, "0", 1);

        //蓝灯
        write(b_fd, "255", 3);
        //延时1秒
        sleep(1);
        write(b_fd, "0", 1);

        //绿灯
        write(g_fd, "255", 3);
        //延时1秒
        sleep(1);
        write(g_fd, "0", 1);
    }
    


    return 0;
}