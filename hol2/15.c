/*
============================================================================
Name : 15.c
Author : Abhipsa Panda
Description :Write a simple program to send some data from parent to the child process.
Date: 8th Oct,2023
============================================================================
*/


#include<unistd.h>
#include<stdio.h>

int main()
{
 int fd[2];
 pipe(fd);
   char buf[100];
 if(fork())
 {
  close(fd[0]);
  printf("\n enter message to child:");
  scanf("%[^\n]", buf);
  write(fd[1],buf,sizeof(buf));
 }
 else
 {
  close(fd[1]);
  read(fd[0],buf,sizeof(buf));
  printf("\n message from parent : %s",buf);
 }
 return 0;
}
 
  to
