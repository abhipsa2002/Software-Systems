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
s.sin_port = htons(5000); // Must be same port as specified in server
// Connect client socket sd to server
connect(sd, (void*) (&s), sizeof(s)); 
// Send message to server
write(sd, "Hello Server \n", 17);
read(sd, buf, sizeof(buf));
printf("Message from server: %s\n", buf);
return 0;
}
