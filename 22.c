/*
============================================================================
Name : 22.c
Author : Abhipsa Panda
Description: Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 8th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 #include <sys/types.h>
 #include <sys/wait.h>

int main()
{
 int fd;
 fd = open("22.txt",O_CREAT|O_RDWR|O_APPEND,0777);
 if(!fork()) //child process
 {
 	write(fd,"Hi from child\n",sizeof("Hi from child\n"));
 }
 else
 {
  	write(fd,"Hello from parent\n",sizeof("Hello from parent\n"));
 }
 wait(0);
/* char buf[100];
 read(fd,buf,sizeof(buf));
 printf("\n output of the file \n %s",buf);*/
 return 0;
 }
 
