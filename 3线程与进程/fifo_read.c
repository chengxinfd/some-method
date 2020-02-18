/*************************************************************************
	> File Name: read.c
	> Author: 
	> Mail: 
	> Created Time:
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define PATH  "/home/xwq/tmp/fifo"


int main()
{
	int ret,fd,buf;
	//创建有名管道文件
	ret = mkfifo(PATH,0666);
	if(ret != 0)
	{
		perror("mkfifo err!");
		return -1;
	}
	//打开有名管道，生成文件描述符
	fd = open(PATH,O_RDONLY);
	if(fd < 0)
	{
		perror("open fifo err!");
		return -1;
	}
	
	//循环读取数据
	while(1)
	{
		buf =0;
		ret = read(fd,&buf,sizeof(int));
		if(ret == 0)
		{
			fprintf(stderr,"the fifo is close!\n");
			return -1;
		}
		else
		{
			printf("buf = %d\n",buf);
		}
	}
	
	return 0;
}

