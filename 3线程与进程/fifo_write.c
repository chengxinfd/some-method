/*************************************************************************
	> File Name: fifo.c
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
	int fd,ret,buf;
	//打开有名管道
	fd = open(PATH,O_WRONLY);
	if(fd < 0)
	{
		perror("open fifo err!");
		return -1;
	}
	
	buf = 7;
	//向管道中写入数据
	while(buf--)
	{	
		write(fd,&buf,sizeof(int));
		sleep(1);
	}
	close(fd);

		return 0;
}

