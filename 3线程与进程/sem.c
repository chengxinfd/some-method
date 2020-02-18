/*************************************************************************
	> File Name: sem.c
	> Author: 
	> Mail: 
	> Created Time:
 ************************************************************************/

#include<stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t sem;
//生产者
void * pthread1(void * tmp)
{
	// v操作 释放资源 产出产品
	int i = 6,num;
	while(i--)
	{
		printf("我生产了一个产品！\n");
		sem_post(&sem);
		sem_getvalue(&sem,&num);
		printf("库存数量 %d\n",num);
		sleep(1);
	}
	
	pthread_exit(NULL);
}

//消费者  消费产品
void * pthread2(void * tmp)
{
	//p操作 申请得到产品
	int num;
	while(1)
	{
		sem_wait(&sem);
		printf("我得到了一个产品！消费掉了\n");
		sem_getvalue(&sem,&num);
		printf("消费后库存数量 %d\n",num);
		sleep(1);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t tid1,tid2;
	int ret;
	ret = sem_init(&sem, 0, 0);
	if(ret != 0)
	{
		fprintf(stderr,"sem_init err!\n");
		return -1;
	}
	
	//创建生产者 线程
	pthread_create(&tid1,NULL,pthread1,NULL);
	
	//创建消费者 线程
	pthread_create(&tid2,NULL,pthread2,NULL);
	
	
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

	return 0;
}


