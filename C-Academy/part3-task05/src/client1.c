/*
  Name:       client1.c

  Purpose:    To send the characters to server, receive converted the characters to uppercase
              and prints the text.
  
*/
#include <stdio.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>


void run_client()
{
  int my_socket;
  struct sockaddr_in address;
  char buffer[1024];
  char message[] = "example message";

  
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
    exit(1);
  }
  
  printf("Enter the message to send : ");
  scanf("%s", message);
    
  send(my_socket, message, sizeof(message), 0);
  recv(my_socket, buffer, sizeof(message), 0);

  printf("Answer from server: %s\n", buffer);

}
