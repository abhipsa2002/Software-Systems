#include<unistd.h>
#include<stdio.h>
int main()
{
 int fd1[2],fd2[2];
 pipe(fd1);
 pipe(fd2);
 char buf[100],buf2[100];
 if(fork()) //write to pipe1 and read from pipe2
 {
  printf("\n enter msg to child:");
  scanf("%[^\n]",buf);
  close(fd1[0]);
  close(fd2[1]);
  write(fd1[1],buf,sizeof(buf));
  read(fd2[0],buf2,sizeof(buf2));
  printf("\n msg from parent: %s",buf2);
 }
 else
 {
  close(fd1[1]);
  close(fd2[0]);
  read(fd1[0],buf,sizeof(buf));
  printf("\n message from parent: %s",buf);
  printf("\n enter message to parent:");
  scanf("%[^\n]",buf2);
  write(fd2[1],buf2,sizeof(buf2));
 }
 return 0;
 }
