#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<linux/input.h>
#include<linux/input-event-codes.h>

//KEY按键
const char defaul_path[] = "/dev/input/by-path/platform-gpio-keys-event";

int main(int argc, char* argv[])
{
    int fd;
    struct input_event event;
    char* path;

    printf("This is input_key demo\n");

    //无输入参数则使用默认事件设备
    if (argc > 1){
        path = argv[1];
    }else{
        path = (char*)defaul_path;
    }
    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        printf("Fail to open the device: %s .", path);
    }
    printf("Test device :%s.\nWating for input...\n", path);

    while (1)
    {
        if (read(fd, &event, sizeof(event)) == sizeof(event)){
            if (event.type != EV_SYN)
            {
                printf("Event: time %ld.%ld, type %d, code %d, value %d\n",
                                event.time.tv_sec, event.time.tv_usec,
                                event.type,
                                event.code,
                                event.value);
            }        
        }
    }
    close(fd);

    return 0;
}

