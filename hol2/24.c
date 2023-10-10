
/*
============================================================================
Name : 24.c
Author : Abhipsa Panda
Description : Write a program to create a message queue and print the key and message queue id.
Date: 8th Oct,2023
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>   
#include <sys/msg.h>  
#include <stdio.h>     
#include <unistd.h>   


int main() {
key_t key = ftok(".", 'a');
int msgid = msgget(key, IPC_CREAT|IPC_EXCL|0744);
// %0x for Hexadecimal value
printf("key=0x%0x\t msgid=%d\n", key, msgid);
return 0;
}
