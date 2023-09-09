/*
============================================================================
Name : 24.c
Author : Abhipsa Panda
Description: Write a program to create an orphan process.
Date: 8th Sept, 2023.
============================================================================
*/

#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>

int main()
{ 
 
 if(!fork())
 {
   printf("pid of child : %u\n",getpid());
   printf("pid of parent before orphan : %u\n",getppid());
   sleep(2);
   printf("pid of parent after orphan : %u\n",getppid());  
 }
 else
 {
   printf("pid of parent:%u\n",getpid());
   exit(0);
 }
 return 0;
}
 
