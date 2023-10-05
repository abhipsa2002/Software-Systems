Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
#include<stdio.h>
#include<unistd.h>
int main()
{
 int fd[2];
 int j = pipe(fd);
 if(j==-1) return 0;
 write(fd[1],"hello",sizeof("hello"));
 char buf[100];
 read(fd[0],buf,sizeof(buf));
 printf("\n message written is : %s",buf);
 return 0;
}
 
