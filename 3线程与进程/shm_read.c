#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <sys/ipc.h>
#include <sys/shm.h>

// gcc write.c -o write
int main() {
	// 1 创建  "共享内存"   key = 0x1000
	// int shmget(key_t key, size_t size, int shmflg);
	int shmid = shmget(0x1000, 4096, IPC_CREAT | 0666);
	if(shmid == -1){ 
		perror("shmget 0x1000:4096 ERROR!"); 
		exit(0); 
	}


	// 2. 映射
	// void *shmat(int shmid, const void *shmaddr, int shmflg); // SHM_REONLY
	void *shm_addr = shmat(shmid, NULL, 0);
	if(shm_addr == (void *)-1){
		perror("shmat ERROR!"); 
		exit(0);
	}

	// 3.  访问
	char *str = (char *)shm_addr;
	puts(str);


	// 4. int shmdt(const void *shmaddr);
	if(shmdt(shm_addr) == -1){
		perror("shmdt() ERROR!"); 
		exit(0);
	}

	exit(0);	

	return 0;
}
