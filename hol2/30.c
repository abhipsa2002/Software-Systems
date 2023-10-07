//30. Write a program to create a shared memory.
// a. write some data to the shared memory
// b. attach with O_RDONLY and check whether you are able to overwrite.
// c. detach the shared memory
// d. remove the shared memory

#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/shm.h> 
#include <unistd.h>    
#include <stdio.h> 

int main()
{
	 char* data;
	 int key=ftok(".",'b');
	 int id=shmget(key,100,IPC_CREAT|0766);
	 data=shmat(id, (void *)0, 0);
	 printf("Enter data to write to shared memory \n");
	 scanf("%[^\n]",data);
	 printf("Reading from the shared file: \n");
	 //data = shmat(sId, (void *)0, SHM_RDONLY);
	 printf("%s\n",data);
	 printf("Enter to delete shared memory");
	 getchar();
	 getchar();
	 shmdt(data);
	 shmctl(id , IPC_RMID, NULL);
	 return 0;
}
