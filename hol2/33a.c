#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/ip.h>
#include <stdio.h>      
#include <unistd.h>   

//code for server part
int main()
{
	struct sockaddr s,c;
	int sd=socket(AF_UNIX,SOCK_STREAM,0);
	s.sin_family=AF_UNIX;
	s.sin_addr.s_addr=INADDR_ANY; //server and client in the same system
	s.sin_port=htons(5000); //port number=5000
	bind(sd,&s,sizeof(s));
	listen(sd,5); 
	int nsd=accept(sd,(void*)c,&sizeof(c));
	char buf[100];
	read(nsd,buf,sizeof(buf));
	printf("message from client: %s\n",buf);
	write(nsd,"hii",4);
	return 0;
}
