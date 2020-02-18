/*************************************************************************
	> File Name: mutex.c
	> Author: 
	> Mail: 
	> Created Time: 
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>

pthread_mutex_t mut;  //锁本身 锁终端的打印

void *th1 (void *tmp)
{
	int ret,i= 5;
	//线程1获得锁
	ret = pthread_mutex_lock(&mut);
	if(ret < 0)
	{
		fprintf(stderr,"pthread_mutex_lock err!\n");
		return NULL;
	}
	//使用资源 终端的打印
	while(i--)
	{
		printf("in th1 i = %d\n",i);
		sleep(1);
	}
	
	//释放锁
	ret = pthread_mutex_unlock(&mut);
	if(ret < 0)
	{
		fprintf(stderr,"pthread_mutex_unlock err!\n");
		return NULL;
	}

	pthread_exit(NULL);
}

void *th2 (void *tmp)
{
	int ret,i= 10;
	//线程2获得锁
	ret = pthread_mutex_lock(&mut);
	if(ret < 0)
	{
		fprintf(stderr,"pthread_mutex_lock err!\n");
		return NULL;
	}
	//使用资源 终端的打印
	while(i-- > 5 )
	{
		printf("in th2 i = %d\n",i);
		sleep(1);
	}
	
	//释放锁
	ret = pthread_mutex_unlock(&mut);
	if(ret < 0)
	{
		fprintf(stderr,"pthread_mutex_unlock err!\n");
		return NULL;
	}
	

	pthread_exit(NULL);
}

int main()
{
	pthread_t tid1,tid2;
	int ret;
	//初始化互斥锁
	ret = pthread_mutex_init(&mut,NULL);
	if(ret < 0)
	{
		fprintf(stderr,"pthread_mutex_init err!\n");
		return -1;
	}
	
	pthread_create(&tid1,NULL,th1,NULL);
	pthread_create(&tid2,NULL,th2,NULL);
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	//销毁互斥锁
	ret = pthread_mutex_destroy(&mut);
	if(ret < 0)
	{
		fprintf(stderr,"pthread_mutex_destroy err!\n");
		return -1;
	}
	
	return 0;
}


