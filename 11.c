#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	if(argc<2)
		return 1;
	int fd1,fd2,fd3;
	fd1 = open(argv[1],O_RDWR|O_APPEND);
	if(fd1==-1)
	{
		perror("error in opening file");
		return 1;
	}
	//a.dup()
	fd2 = dup(fd1);
	
	if(fd2==-1)
	{	perror("\n dup() failed"); return 1;}
	write(fd1,"original fd",sizeof("original fd"));
	write(fd2,"duplicate fd using dup()",sizeof("duplicate fd using dup()"));
	
	//b. dup2()	
	fd3 = dup2(fd1,10);
	if(fd3==-1)
	{
		perror("dup2() failed");
		return 1;
	}
	write(fd1,"original fd",sizeof("original fd"));
	write(fd3,"duplicate fd using dup2()",sizeof("duplicate fd using dup2()"));
	int fd4 = fcntl(fd1,F_DUPFD);
	if(fd4==-1)
	{
		perror("fcntl() failed");
		return 1;
	}	
	write(fd1,"original fd",sizeof("original fd"));
	write(fd3,"duplicate fd using fcntl()",sizeof("duplicate fd using fcntl()"));
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);	
	return 0;
}

/*gcc 11.c -o 11o
./11o cp.txt
cat cp.txt*/

