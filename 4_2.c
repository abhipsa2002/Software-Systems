#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	int fd;
	fd = open("file.txt",O_RDWR|O_CREAT|O_EXCL);
	
	if(fd==-1)
	{
		if(errno==EEXIST)
			printf("already exits");
		
		return 1;
	}
	printf("opened file %d",fd);
	close(fd);
	return 0;
}
	
