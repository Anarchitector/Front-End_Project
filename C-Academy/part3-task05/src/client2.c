/*
  Name:       client2.c

  Purpose:    To send a number to the server process, receive from the server doubled number and 
              print the result.
  
*/

#include <stdio.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

char message[] = "1234";
char buffer[sizeof(message)];

int main()
{
  int my_socket;
  struct sockaddr_in address;

  my_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (my_socket < 0)
  {
    perror("socket");
    exit(1);
  }

  address.sin_family = AF_INET;
  address.sin_port = htons(3425);
  address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  if (connect(my_socket, (struct sockaddr*)&address, sizeof(address)) <0 )
  {
    perror("connect");
    exit(2);
  }

    send(my_socket, message, sizeof(message), 0);
    recv(my_socket, buffer, sizeof(message), 0);

    printf("%s", buffer);

  return 0;
}
