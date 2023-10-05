#include<unistd.h>
#include<stdio.h>

int main()
{
  int fd[2];
  pipe(fd);
  if(!fork()) //ls -Rl
  {

  	close(fd[0]);
  	fcntl(fd[1],F_DUPFD,1) //1 will be closed as it is already in use
  	execl("/usr/bin/ls","ls","-Rl",NULL);
  	
  }
  else  //wc
  {

  	close(fd[1]);
  	fcntl(fd[0],F_DUPFD,0) //1 will be closed as it is already in use
  	execl("/usr/bin/wc","wc",NULL);
  }
  return 0;
} 

