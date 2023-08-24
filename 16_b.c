#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include <sys/file.h>
#include<unistd.h>

int main(int arc,char* argv[]) 
{
	struct flock lock;
	int fd;
	fd = open(argv[1], O_RDWR);
	if(fd==-1)
	{
	   perror("error in opening file");
	   return 1;
	}
	//read lock
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	//perform mandatory locking 
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("Before entering into critical section \n");
	fcntl(fd, F_SETLKW, &lock);
	printf("Inside the critical section\n");
	printf("Press ENTER to unlock");
	getchar(); //waits until it receives an output from STDIN
	printf("File unlocked \n");
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("End\n");
	return 0;
}
