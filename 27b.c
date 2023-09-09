/*
============================================================================
Name : 27b.c
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
 int i = execlp("ls","ls","-Rl",NULL);
  if(i==-1) {
 	perror("error in execlp:");
 	return;
 	}
 return 0;
 }
 
