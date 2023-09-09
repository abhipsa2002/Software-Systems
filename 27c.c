/*
============================================================================
Name : 27c.c
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
// char *env_var[]={"MYENV = Hii",NULL};
 int i = execle("/usr/bin/ls","ls","-Rl",NULL,NULL);
  if(i==-1) {
 	perror("error in execle:");
 	return;
 	}
 return 0;
 }
