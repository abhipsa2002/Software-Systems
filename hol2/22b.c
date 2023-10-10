/*
============================================================================
Name : 22b.c
Author : Abhipsa Panda
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
	      system call with FIFO.
Date: 8th Oct,2023
============================================================================
*/

#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>    
int main()
{
char buf[100];	
int fd=open("./fifo1",O_WRONLY);
printf("Enter data to write: \n");
scanf("%[^\n]", buf);
write(fd,&buf,sizeof(buf));
return 0;
}
