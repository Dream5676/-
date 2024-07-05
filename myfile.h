#ifndef __FILERW_H__
#define __FILERW_H__

//自定义ioctl命令码
#define FILE_READ _IOR('F',1,char[32])
#define FILE_WRITE _IOW('F',0,char[32])
#define CMD_SIZE(cmd) ((cmd>>16)&(0x3fff))


#endif
