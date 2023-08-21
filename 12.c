#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char* argv[])
{
	if(argc<2)
		return 1;
	int fd;
	fd = open(argv[1],O_RDWR);
	if(fd==-1)
	{
		perror("error in opening file");
		return 1;
	}
	int check = fcntl(fd,F_GETFL);	
	if(check==-1)
	{
		perror("error");
		return 1;
	}

	switch(check){
    	case 32768 : printf("r"); break;
    	case 32769 : printf("w"); break;
    	case 33793 : printf("a"); break;
    	case 32770 : printf("r+ || w+"); break;
    	case 32794 : printf("a+"); break;
	}
	return 0;
}
