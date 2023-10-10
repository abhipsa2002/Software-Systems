/*
============================================================================
Name : 19.c
Author : Abhipsa Panda
Description : Create a FIFO file by
	a. mknod command
	b. mkfifo command
	c. use strace command to find out, which command (mknod or mkfifo) is better.
	c. mknod system call
	d. mkfifo library function
Date: 8th Oct,2023
============================================================================
*/
#include<sys/types.h> 
#include<sys/stat.h>  
#include<fcntl.h>     
#include<unistd.h>    
#include<stdio.h>     

int main()
{
    char *mkfifoName = "./fifo_mkfifo";     
    char *mknodName = "./fifo_mknod";  

    int mkfifo_status, mknod_status; // 0 -> Success, -1 -> Error

    // Using `mkfifo` library function
    mkfifo_status = mkfifo(mkfifoName, 0744);

    if (mkfifo_status == -1)
        perror("Error while creating FIFO file!");
    else
        printf("Succesfully created FIFO file. Check using `ll` or `ls -l` command!\n");

    // Using `mknod` system call
    mkfifo_status = mknod(mknodName, __S_IFIFO | 0744, 0);

    if (mknod_status == -1)
        perror("Error while creating FIFO file!");
    else
        printf("Succesfully created FIFO file. Check using `ll` or `ls -l` command!\n");
    return 0;
}

//a. mknod fifo_19a p
//b. mkfifo fifo_19b
/*c. kfifo actually calls mknod() and this
mkfifo() is just doing some extra steps on top of mknod() because mkfifo() is a library function
whereas mknod() is the actual system call.
Therefore, mknod() is always going to be faster than mkfifo().*/
