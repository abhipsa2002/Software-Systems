#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
char buf[100];
int fd = open("./fifo1", O_RDONLY);
read(fd, buf, sizeof(buf));
printf("\n The message entered: %s\n",buf);
return 0;
}
