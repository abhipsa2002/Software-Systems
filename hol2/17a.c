/*
============================================================================
Name : 17a.c
Author : Abhipsa Panda
Description :Write a program to execute ls -l | wc.
	a. use dup
	b. use dup2
	c. use fcntl
Date: 8th Oct,2023
============================================================================
*/

#include<unistd.h>
#include<stdio.h>

int main()
{
  int fd[2];
  pipe(fd);
  if(!fork()) //ls -Rl
  {
  	close(1);
  	close(fd[0]);
  	dup(fd[1]); //newfd will be 1
  	execl("/usr/bin/ls","ls","-Rl",NULL);
  	
  }
  else  //wc
  {
  	close(0);
  	close(fd[1]);
  	dup(fd[0]);
  	execl("/usr/bin/wc","wc",NULL);
  }
  return 0;
}

//to verify execute ls -Rl| wc in cmd line
