modname=myfile

KERNELDIR:= /lib/modules/$(shell uname -r)/build  #编译x86格式

PWD:= $(shell pwd)

all:
	make -C $(KERNELDIR) M=$(PWD) modules
	@#make -C $(KERNELDIR)切换路径到内核顶层目录下，读取Makefile文件，对着它执行make
	@#make M=$(PWD) modules M指定的是编译模块的路径，编译M指定路径下的模块
clean:
	make -C $(KERNELDIR) M=$(PWD) clean
	@#make -C $(KERNELDIR)切换路径到内核顶层目录下，读取Makefile文件，对着它执行make
	@#make M=$(PWD) clean M指定的是清除模块的路径，清除M指定路径下的编译的中间文件及目标文件
obj-m:=$(modname).o #最终编译生成的模块名demo.ko
