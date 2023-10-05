#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<sys/select.h>

int main()
{
fd_set rfds;
struct timeval tv;
tv.tv_sec = 10;
char buff[100];
int fd = open("./fifo1", O_RDONLY);
FD_ZERO(&rfds);
FD_SET(fd, &rfds);
int ret = select(fd + 1, &rfds, NULL, NULL, &tv);
if(ret==0) 
printf("No data is available for reading yet\n");
else {
printf("Data is available now\n");
read(fd, &buff, sizeof(buff));
printf("Data from FIFO: %s\n", buff);
}
return 0;
}
