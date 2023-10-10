/*
============================================================================
Name : 21a.c
Author : Abhipsa Panda
Description : Write two programs so that both can communicate by FIFO - Use two way communication.
Date: 8th Oct,2023
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
char buff1[100],buff2[100];
fd1 = open("./myfifo1", O_WRONLY);
fd2 = open("./myfifo2", O_RDONLY);
printf("Enter the text:\n");
scanf(" %[^\n]", buff1);
write(fd1, buff1, sizeof(buff1));
read(fd2, buff2, sizeof(buff2));
printf("The text from FIFO file: %s\n", buff2);
return 0;
}
