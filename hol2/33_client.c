/*
============================================================================
Name : 33_client.c
Author : Abhipsa Panda
Description :Write a program to communicate between two machines using socket.
Date: 8th Oct,2023
============================================================================
*/
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/ip.h>
#include <stdio.h>      
#include <unistd.h>   

//code for client
int main() {
struct sockaddr_in s;
int sd;
char buf[80];
sd = socket(AF_UNIX, SOCK_STREAM, 0);
s.sin_family = AF_UNIX;
s.sin_addr.s_addr = INADDR_ANY;
s.sin_port = htons(5555); // Must be same port as specified in server
// Connect client socket sd to server
connect(sd, (struct sockaddr*) (&s), sizeof(s)); 
// Send message to server
write(sd, "Hello Server \n", sizeof("Hello Server \n"));
read(sd, buf, sizeof(buf));
printf("Message from server: %s\n", buf);
close(nsd);
	close(sd);
	return 0;
}
