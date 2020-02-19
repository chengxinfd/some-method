#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_LEN 32
struct myMsg {
	long mtype;
	char buf[MSG_LEN];
};

// gcc write.c -o write
int main() {
	// 1 创建  "消息队列"   key = 0x1000

	key_t key = 0x1000;
	// int msgget(key_t key, int msgflg);
	int msgid = msgget(key, IPC_CREAT | 0666);
	if(msgid == -1){ 
		perror("msgget IPC_CREAT | 0666 ERROR!"); 
		exit(0); 
	}

	// 2. int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
	struct myMsg msg = { 100, "hello world"};
	if(msgsnd(msgid, &msg, MSG_LEN, 0) == -1) { 
		perror("Msg Send error!"); 
		exit(0); 
	}


	// 3. 删除MSG对象
	// int msgctl(int msqid, int cmd, struct msqid_ds *buf);
	if(msgctl(msgid, IPC_RMID, 0) == -1){
		perror("IPC_RMID ERROR!"); 
		exit(0); 
	}

	return 0;
}
