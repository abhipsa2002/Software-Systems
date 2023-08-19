#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
//implement cp cmd
int main(int argc, char* argv[]) //argc = arg count and argv = arg value
{
	if(argc!=3){
		printf("you're useless");
		return 1;
	}
	int fd1,fd2;
	fd1 = open(argv[1],O_RDONLY);
	fd2 = open(argv[2],O_WRONLY|O_CREAT,0744); //ORING THE MACROS WILL GIVE THE PROPERTIES OF BOTH
	if(fd1==-1 || fd2==-2) 
	{
		printf("useless");
		return 1;
	}
	while(1){
		char buf;
		int char_read=read(fd1,&buf,1);
		if(char_read==0)
			break;
		int char_written = write(fd2,&buf,1);
		//if read return 0 its is EOF else returns 1
	}
	int close1 = close(fd1);
	int close2 = close(fd2);
	if(close1==-1 || close2==-1)
		printf("totally useless");
	return 0;
}
