/*
============================================================================
Name : 14.c
Author : Abhipsa Panda
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
	the monitor.
Date: 8th Oct,2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
int main()
{
 int fd[2];
 int j = pipe(fd);
 if(j==-1) return 0;
 write(fd[1],"hello",sizeof("hello"));
 char buf[100];
 read(fd[0],buf,sizeof(buf));
 printf("\n message written is : %s",buf);
 return 0;
}
 
