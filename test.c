#include <head.h>
#include<sys/ioctl.h>
#include"myfile.h"

int main(int argc,const char* argv[])
{
    int fd_R,fd_W,fd;
    int ret;
    char data[32] = {0};

    //打开文件
    if((fd_R = open("/home/linux/qudong/ce_shi_ti/file_R.txt",O_RDONLY,0666)) == -1)
    {
        PRINT_ERR("open error\n");
    }

    if((fd_W = open("/home/linux/qudong/ce_shi_ti/file_W.txt",O_WRONLY|O_APPEND,0666)) == -1)
    {
        PRINT_ERR("open error\n");
    }

    if((fd = open("/dev/myfile",O_RDWR,0666)) == -1)
    {
        PRINT_ERR("open error\n");
    }

    while(1)
    {
        char s[16] = {0};
        printf("请输入需要的操作[Read/Write]:");
        fgets(s,sizeof(s),stdin);
        s[strlen(s) - 1] = '\0';
        if(!strcmp(s,"Read"))
        {
            //将文件file_R中的数据,写入到内核中
            read(fd_R,data,sizeof(data));
            printf("%s\n",data);
            ret = ioctl(fd,FILE_WRITE,data);
            if(ret < 0)
            {
                printf("ret = %d,failed to write data\n",ret);
            }
        }else if(!strcmp(s,"Write"))
        {
            //从内核中读取数据写入到文件file_W中
            ret = ioctl(fd,FILE_READ,data);
            if(ret < 0)
            {
                printf("ret = %d,failed to read data\n",ret);
            }
            //清除之前数据
            memset(data,sizeof(data),0);
            printf("data = %s;%s:%d\n", data, __func__, __LINE__);
            write(fd_W,data,sizeof(data));
        }else if(!strcmp(s,"Exit"))
        {
            //关闭文件
            close(fd);
            close(fd_R);
            close(fd_W);
            return 0;
        }else
        {
            //关闭文件
            close(fd);
            close(fd_R);
            close(fd_W);
            printf("输入无效！\n");
            return 0;
        }
    }


    //关闭文件
    close(fd);
    close(fd_R);
    close(fd_W);
    return 0;
}
