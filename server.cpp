#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
int main (void)
{
    int S_ocket,new_Socket;

    sockaddr_in server_address,client_address;
    socklen_t client_address_len;

    char buffer[BUFFER_SIZE];

   S_ocket=socket(AF_INET,SOCK_STREAM,0);

   if (S_ocket<0)
   {
        perror("couldn't init socket");
        exit(EXIT_FAILURE);
        
        
   }
   else 
    {
        
        server_address.sin_family=AF_INET;
        server_address.sin_port=htons(8080);
        server_address.sin_addr.s_addr=htonl(INADDR_ANY);

    }

    if (bind(S_ocket,(struct sockaddr *)&server_address,sizeof(server_address))<0)
    {
        perror("couldn't bind socket");
    }

    if (listen(S_ocket,5)<0)
    {
        perror("listen");
        exit(EXIT_FAILURE);

    }

    client_address_len=sizeof(client_address);
    new_Socket=accept(S_ocket,(struct sockaddr *)&client_address,&client_address_len);

    if (new_Socket<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    ssize_t bytes_received;

    while (bytes_received>0)
    {
        bytes_received=recv(new_Socket,buffer,sizeof(buffer),0); //receive the request through the accept socket and save it on bytes_received variable
        printf("Received %zd bytes: %s\n",bytes_received,buffer); 


    }
    if (bytes_received==-1)
    {
        perror("receive");
        exit(EXIT_FAILURE);
    }

    
    



    return 0;
}
