#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include <sys/file.h>
#include<unistd.h>

int main(int argc,char* argv[]) 
{
	struct {
	int tno;
	}db;
	db.tno = 1;
	struct flock lock;
	int fd;
	fd = open("db", O_RDWR);
	//write lock
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	//perform mandatory locking 
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("Before entering into critical section \n");
	fcntl(fd, F_SETLKW, &lock);
	printf("Inside the critical section\n");
	read(fd, &db, sizeof(db));
	printf("Current ticket number: %d \n", db.tno);
	db.tno++; 
	lseek(fd, 0, SEEK_SET); //due to initial read file pointer is currently at end, so bring it to start to overwrite the exisitng value
	write(fd, &db, sizeof(db));
	printf("Press enter to unlock\n");
	getchar();
	lock.l_type = F_UNLCK; 
	fcntl(fd, F_SETLK, &lock);
	printf("Exited critical section\n");
	return 0;
}
