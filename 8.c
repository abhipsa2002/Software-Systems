#include<stdio.h>
#include<unistd.h>

#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
int main(int argc, char *argv[])
{	if(argc!=2) {printf("error"); return 0;}
	int fd = open(argv[1],O_RDONLY);
	if(fd==-1) 
	{
		printf("error");
		return 1;
	}
	while(1)
	{
		char buf;
		int r = read(fd,&buf,1);
		if(r==0) break;
		if(buf!='\n')
			write(1,&buf,1);
		else
		  printf("\n");
	}
	int close1=close(fd);
	if(close1==-1)
	{
		printf("not closed");
		return 1;
	}
	return 0;
}

