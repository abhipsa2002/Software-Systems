/*
============================================================================
Name : 27d.c
Author : Abhipsa Panda
Description: Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp
Date: 8th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main()
{
 char *arg[]={"ls,","-Rl",NULL);
 int i = execv("/usr/bin/ls",arg);
  if(i==-1) {
 	perror("error in execv:");
 	return;
 	}
 return 0;
}
