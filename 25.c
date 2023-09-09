/*
============================================================================
Name : 25.c
Author : Abhipsa Panda
Description: Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 8th Sept, 2023.
============================================================================
*/


#include <unistd.h>    
#include <sys/types.h> 
#include <sys/wait.h>  
#include <stdio.h>
 int main()
 { pid_t par,pid1,pid2,pid3;
   par= getpid();
    printf("Process ID of parent: %u\n",par);
   if((pid1=fork())==0) //child1
   {
   	
   	printf("Process ID of child1: %u\n",getpid());
   	
   }
   else
   {
   	if((pid2=fork())==0) //child 2
   	{

   	 printf("Process ID of child2: %u\n",getpid());
   	 printf("Entering process 1 into sleep for 10s \n");
   	 sleep(10);
   	}
   	else
   	 {
   	  if((pid3=fork())==0){ //child 3
   	   	
   	   	printf("Process ID of child3: %u\n",getpid());
   	   }
   	   else{
   	      waitpid(pid2,NULL,0);
   	  }
   	 }   
  }
  printf("exited: %u\n",getpid());
  return 0;
  }
   
