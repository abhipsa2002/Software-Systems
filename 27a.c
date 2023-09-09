/*
============================================================================
Name : 27a.c
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
 int i = execl("/usr/bin/ls","ls","-Rl",NULL);
 if(i==-1) {
 	perror("error in execl:");
 	return;
 	}
 return 0;
 }
 
 //execute whereis ls command to know the executable file path of the command ls 
