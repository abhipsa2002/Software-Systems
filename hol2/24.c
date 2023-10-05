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
}
