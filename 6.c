#include<stdio.h>
#include<unistd.h>
int main()
{	int n;
	printf("\n enter the number of characters you want to write:");
	scanf("%d",&n);
	char buf[n];
	int i;
	i = read(0,buf,sizeof(buf));
	write(1,buf,i);
	return 0;
}
