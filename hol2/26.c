
/*
============================================================================
Name : 26.c
Author : Abhipsa Panda
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 8th Oct,2023
============================================================================
*/
#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <stdio.h>   
#include <unistd.h> 
#include<string.h>
int main() 
{
	struct msg {
	long int m_type;
	char message[80];
	} mq;
	key_t key = ftok(".", 'a');
	int id = msgget(key, 0);
	if(id==-1)
	{
	perror("ERROR: ");
	return -1;
	}
	printf("Enter message type: ");
	scanf("%ld", &mq.m_type);
	getchar(); //to prevent \n from prev inp from buffer to going into the scanf
	printf("Enter message text: "); 
	scanf("%[^\n]", mq.message);
	int size = strlen(mq.message);
	msgsnd(id, &mq, size + 1, 0); //size+1 is to include the NULL character
	return 0;
}

//OUTPUT
/* ------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x61031e5d 0          abhipsa    744        4            1           
*/
