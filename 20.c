/*
============================================================================
Name : 20.c
Author : Abhipsa Panda
Description: Find out the priority of your running program. Modify the priority with nice command.
Date: 8th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
 int pid = getpid();
 int nval = getpriority(PRIO_PROCESS,pid);
 printf("Current nice value: %d of process: %u\n",nval,pid);
 getchar();
  nice(5); //priority decreases
  nval = getpriority(PRIO_PROCESS,pid);
 printf("Updated nice value: %d of process: %u\n",nval,pid);
 while(1);
 return 0;
}

//run with sudo if want to incr priority i.e. nice(-ve) else you can exe directly

