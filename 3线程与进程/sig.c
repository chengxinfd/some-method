/*************************************************************************
	> File Name: sig.c
	> Author: 
	> Mail: 
	> Created Time: Fri 21 Apr 2017 02:40:36 PM HKT
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

 void sighandler(int sig)
 {
	 printf("sig=%d\n",sig);
	 return ;
 }




int main()
{
	pid_t pid;
	int ret;
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
		kill(getppid(),SIGCHLD);
		sleep(2);
		exit(0);
	}
	else if (pid > 0)
	{
		//在父进程中
		signal(SIGCHLD, sighandler);
		
		wait(&ret);
	}
	
	return 0;
}


