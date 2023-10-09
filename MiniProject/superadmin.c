#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

#include "./structures/admin.h"

int getSno(){
	int fd=open("./data/AdminData",O_RDONLY,0744);
	if (fd==-1)
    	{
        	return -1;
    	}
	struct admin prev;
	lseek(fd,(-1)*sizeof(struct admin),SEEK_END);
	read(fd,&prev,sizeof(struct admin));
	close(fd);
	return prev.sno+1;
}

int main(){
	struct admin nadmin;
	nadmin.sno=getSno();
	int fd=open("./data/AdminData",O_RDWR | O_CREAT | O_APPEND,0744);
	printf("Enter the Admin's username: ");
	scanf(" %[^\n]",nadmin.usrname);
	printf("Enter the password(max 10 characters): ");
	scanf(" %[^\n]",nadmin.password);
	printf("Your Sno is : %d\n",newAdmin.sno);
	write(fd,&nadmin,sizeof(struct admin));
	char choice;
	printf("Do you want to add more admins(Y/N)? ");
	scanf("%c",&choice);
	while(choice!='N'){
		nadmin.sno=getSno();
		printf("Enter the Admin's username: ");
		scanf(" %[^\n]",nadmin.usrname);
		printf("Enter the password(max 10 characters): ");
		scanf(" %[^\n]",nadmin.password);
		printf("Your userID is : %d\n",nadmin.sno);
		write(fd,&nadmin,sizeof(struct admin));
		printf("Do you want to add more admins(Y/N)? ");
		scanf("%c",&choice);
	}
	close(fd);
	return 0;
}
