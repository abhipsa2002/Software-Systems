
//28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <stdio.h>   
#include <unistd.h>    
#include <errno.h>

int main()
{
	struct msqid_ds mq;
	key_t key=ftok(".",'a');
	int id=msgget(key,0);
	printf("Key: %d\n", key);
    	printf("Message Queue Identifier: %d\n", id);
	msgctl(id, IPC_STAT, &mq);
	mq.msg_perm.mode=0666;
	msgctl(id, IPC_SET, &mq);
	return 0;
}


//check permission by using ipcs -q
