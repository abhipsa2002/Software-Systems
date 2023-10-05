/*26. Write a program to send messages to the message queue. Check $ipcs -q*/

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
printf("Enter message type: ");
scanf("%ld", &mq.m_type);
getchar(); //to prevent \n from prev inp from buffer to going into the scanf
printf("Enter message text: "); 
scanf("%[^\n]", mq.message);
int size = strlen(mq.message);
msgsnd(id, &mq, size + 1, 0); //size+1 is to include the NULL character
return 0;
}
