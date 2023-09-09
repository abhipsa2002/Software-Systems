/*
============================================================================
Name : 14.c
Author : Abhipsa Panda
Description: Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 8th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
int main(int argc,char *argv[])
{
    	if(argc!=2)
   	 {
         	perror("\n insufficient arguments");
         	return 0;
    	}
   
	struct stat file_info;
	stat(argv[1],&file_info);
	if(S_ISREG(file_info.st_mode))
		printf("\nRegular File");
    	else if(S_ISDIR(file_info.st_mode))
     		printf("\n Directory");
    	else
      		printf("\nSome other type of file");
 	return 0;
}
