/*27. Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag*/

#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <stdio.h>   
#include <unistd.h> 
#include <stdlib.h>

int main()
{
struct msg {
long int m_type;
char message[80];
}mq;
key_t key = ftok(".",'a');
int id = msgget(key,0);
printf("Enter message type to retrive: ");
scanf("%ld", &mq.m_type);
int ret = msgrcv(id, &mq, sizeof(mq.message), mq.m_type,0);
if (ret == -1)
	{
	perror("not found");
	exit(-1);
	}	
printf("Message type: %ld\n Message: %s\n", mq.m_type, mq.message);
return 0;
}

//run gcc 26.c and enter the msg of required mgstype 
