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
	int fd;
	//create a file if doesn't exist, to store ticket number
	fd = open("db", O_CREAT|O_RDWR, 0744);
	if(fd==-1)
	{ 
		perror("error in opening file");
		return 0;
	}
	write(fd,&db,sizeof(db));
	close(fd);
	//store the ticket number to struct db from file
	fd = open("db", O_RDONLY);
	read(fd,&db,sizeof(db));
	printf("Ticket no: %d\n", db.tno);
	close(fd);
	return 0;
}
