#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include <sys/file.h>
#include<unistd.h>

int main()
{
	struct {
		int tno;
		int tik_no;
	} db;
	struct flock lock;
	int i;
	printf("\n Enter the train number to book ticket (1,2,3): ");
	scanf("%d",&i);
	if(i>3)
	{
	 printf("out of range");
	 return 1;
	}
	lock.l_type=F_RDLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=(i-1)*sizeof(db);
	lock.l_len=sizeof(db);
	lock.l_pid=getpid();
	int fd = open("rec.txt",O_RDONLY);
	if(fd==-1)
	{
	  perror("error");
	  return 0;
	}
	//start read lock
	printf("\n before entering into critical section");
	fcntl(fd,F_SETLKW,&lock);
	printf("\n Inside critical section");
	lseek(fd,(i-1)*sizeof(db),sizeof(db));
	read(fd,&db,sizeof(db));
	printf("\n current ticket number: %d",db.tik_no);
	printf("\n press enter to exit the critical section");
	getchar();
	getchar(); //due to enter train number (1st enter is taken as input for getchar() of critical section)
	lock.l_type=F_UNLCK;
	printf("\n exited the critical section");
	fcntl(fd,F_SETLK,&lock);
	printf("\n booked ticket having ticket number as %d",db.tik_no);
	close(fd);
	return 0;
}
