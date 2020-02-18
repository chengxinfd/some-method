/*************************************************************************
	> File Name: fifo.c
	> Author: 
	> Mail: 
	> Created Time:
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int pd[2];
	int ret;
	char buf[100];
	pid_t pid;
	//创建管道
	ret = pipe(pd);
	if(ret != 0)
	{
		perror("pipe err!");
		return -1;
	}
	//创建子进程
	pid = fork();
	if(pid < 0)
	{
		perror("fork err!");
		return -1;
	}
	else if(pid == 0)
	{
		//在子进程中
		//关闭写端
		close(pd[1]);
		
		while(1)
		{
			memset(buf,0,sizeof(buf));
			//从管道中读取数据
			ret = read(pd[0],buf,sizeof(buf));
			if(ret == 0)
			{
				printf("the write is close!\n");
				exit(0);
			}
			else
			{
				printf("%s",buf);		
			}
		
		}
	}
	else if(pid > 0)
	{
		//在父进程中
		memset(buf,0,sizeof(buf));
		stpcpy(buf,"hello world!\n");
		//关闭读端
		close(pd[0]);
		//向管道中写入数据
		write(pd[1],buf,sizeof(buf));
		close(pd[1]);
		wait(&ret);
	}
	
	
	return 0;
}

