/*
============================================================================
Name : 21.c
Author : Abhipsa Panda
Description: Write a program, call fork and print the parent and child process id.
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
  printf("\n child process id : %u",getpid());
 }
 else
 {
  printf("\n parent process id: %u",getpid());
 }
 return 0;
 }
