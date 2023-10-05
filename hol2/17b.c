#include<unistd.h>
#include<stdio.h>

int main()
{
  int fd[2];
  pipe(fd);
  while(1);
  if(!fork()) //ls -Rl
  {

  	close(fd[0]);
  	dup2(fd[1],1); //1 will be closed as it is already in use
  	execl("/usr/bin/ls","ls","-Rl",NULL);
  	
  }
  else  //wc
  {

  	close(fd[1]);
  	dup2(fd[0],0); //0 will be closed as it is already in use
  	execl("/usr/bin/wc","wc",NULL);
  }
  //while (1) wont work here due to execl()
  return 0;
} 

