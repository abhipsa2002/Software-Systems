#include<unistd.h>
#include<stdio.h>

int main()
{
  int fd[2];
  pipe(fd);
  if(!fork()) //ls -Rl
  {
  	close(1);
  	close(fd[0]);
  	dup(fd[1]); //newfd will be 1
  	execl("/usr/bin/ls","ls","-Rl",NULL);
  	
  }
  else  //wc
  {
  	close(0);
  	close(fd[1]);
  	dup(fd[0]);
  	execl("/usr/bin/wc","wc",NULL);
  }
  return 0;
}

//to verify execute ls -Rl| wc in cmd line
