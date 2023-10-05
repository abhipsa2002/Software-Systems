#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
char buff1[100],buff2[100];
int fd1,fd2;
fd1 = open("./myfifo1", O_RDONLY);
fd2 = open("./myfifo2", O_WRONLY);
read(fd1, buff1, sizeof(buff1));
printf("The text from 1st: %s\n", buff1);
printf("Enter the text to 1st:\n");
scanf(" %[^\n]", buff2);
write(fd1, buff2, sizeof(buff2));
return 0;
}
