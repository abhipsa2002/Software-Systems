#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{	
	char *filename[5] = {"file1.txt","file2.txt","file3.txt","file4.txt","file5.txt"};
	
	for(int i=1 ;i<=5 ;i++)
	{
		creat(filename[i],744);	
	}	
	while(1);
	
	return 0;
}
