#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(int argc, char* argv[])
{ 
   if(argc!=2)
   {
   	printf("totally useless");
   	return 1;
   }
   int fd;
   fd = open(argv[1],O_RDWR);
   if(fd==-1)
   {
    printf("useless");
    return 1;
   }
//read and write 10 bytes to the file
   char buff[10];
   int i = read(0,buff,10);
   write(fd,buff,i);
   off_t l = lseek(fd,10,SEEK_CUR);
   if(l==(off_t)-1)
   {
   	printf("error in lseek");
   	return 1;
   }
   int j = read(0,buff,10);
   write(fd,buff,j);
   int c = close(fd);
   if(c==1)
   {
    printf("\n error in closing the file");
    return 1;
   }
   return 0;
}
// to see the spacing in the cmd line use $od -c 10.txt(file name)
