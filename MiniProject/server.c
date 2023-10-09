#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h> 
#include<unistd.h>
#include<stdbool.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h> 




int main(){
	struct sockaddr_in server,client;
	int sd,nsd,clientLen;
	bool result;
	sd=socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;    
	server.sin_addr.s_addr=INADDR_ANY; 
	server.sin_port=htons(5000);
	int bnd = bind(sd,(struct sockaddr *)&server,sizeof(server));
	if(bnd==-1)
	{
		perror("error in bind()");
		return -1;
	}
	int ls = listen(sd,5);	
	if(ls==-1)
	{
		perror("error in listen()");
		return -1;
	}     
   	printf("Course Management System \n");
	printf("Waiting for Client to connect\n");
	while(1){
		clientLen = sizeof(client);
		nsd=accept(sd,(struct sockaddr *)&client,&clientLen);
		write(1,"Connected to the client\n",sizeof("Connected to the client\n"));
		if(!fork()){
			close(sd);
			serverTask(nsd);
			exit(0);
		}
		else{
			close(nsd);
		}
	}
	return 0;
}
