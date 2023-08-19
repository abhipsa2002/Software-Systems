#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
int main()
{
	int fd;
	fd=creat("f1.txt",0744);
	
	if(fd==-1)
	{
		perror("error");
		return 1;
	}
	printf("file created successfully ");
	printf("\n");
	close(fd);
	return 0;
}

