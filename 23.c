/*
============================================================================
Name : 23.c
Author : Abhipsa Panda
Description: Write a program to create a Zombie state of the running program.
Date: 8th Sept, 2023.
============================================================================
*/

#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
 if(!fork())
 {
  	printf("child process id: %u\n",getpid());
  	printf("exiting... \n");
  	exit(0);
  }
  else
  {	
  	printf(" parent process id: %u\n",getpid());
  	// printf("\n putting parent to sleep ");By default, stdout is often line-buffered, which means that the output is held in a buffer until a newline character (\n) is encountered or until the buffer is full. Only then is the content of the buffer actually displayed on the screen. Therefore, use \n at the end of printf()
  	printf("putting parent to sleep\n");
  	sleep(100);
	printf("parent is awake now\n");
  }
  return 0;
 }
 
 //open a new terminal and give cmd ps -p <pid of child>
 //it will give state output as <defunct> (means zombie)
