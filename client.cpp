#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>


#define BUFFER_SIZE 1024
int main ()
{
    int client_socket;
    sockaddr_in client_address;
    char client_buffer[BUFFER_SIZE]="Hello World";
    std::string message="Hello World";


    client_socket=socket(AF_INET,SOCK_STREAM,0);

    if (client_socket<0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }


    client_address.sin_family=AF_INET;
    client_address.sin_port=htons(8080);
    client_address.sin_addr.s_addr=htonl(INADDR_LOOPBACK);


    if (connect(client_socket,(struct sockaddr *)&client_address,sizeof(client_address))<0)
    {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    ssize_t bytes_to_send;

    bytes_to_send=send(client_socket,client_buffer,sizeof(client_buffer),0);

    



    
    return 0;
}