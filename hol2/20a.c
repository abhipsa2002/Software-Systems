/*
============================================================================
Name : 20a.c
Author : Abhipsa Panda
Description : Write two programs so that both can communicate by FIFO - Use one way communication.
Date: 8th Oct,2023
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
char buf[100];
int fd = open("./fifo1", O_WRONLY);
printf("Enter the message: \n");
scanf(" %[^\n]", buf);
write(fd, buf, sizeof(buf));
return 0;
}
