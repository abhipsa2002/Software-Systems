#include<unistd.h>
#include<stdio.h>
int main()
{
long PIPE_BUF,OPEN_MAX;
PIPE_BUF=pathconf(".",_PC_PIPE_BUF);
OPEN_MAX=sysconf(_SC_OPEN_MAX);
printf("PIPE_BUF= %ld\t OPEN_MAX= %ld\n",PIPE_BUF,OPEN_MAX);
return 0;
}


//PIPE_BUF= 4096	 OPEN_MAX= 1024

