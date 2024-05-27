/*
  Name:      server_func.c

  Purpose:   Functions of string processing
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include "server_func.h"

/*
  Name:     check_str

  Purpose:  Checking if string has only digits or not

  Params:   IN  message - the string of different symbols.

  Returns:  The status of string if it contains only digits or other symbols
*/
str_status check_message(char* message)
{
  int i = 0;
  while (message[i] != '\0')
  {
    if (!(isdigit(message[i])))
    {
      return STR_IS_STR;
    }
    i++;
  }
  return STR_IS_NUM;
} /* check_str */


/*
  Name:     double_the_number_str

  Purpose:  Double the number as a character string

  Params:   IN/OUT  message - the string of digits.

  Returns:  Doubled number as string
*/
void double_the_number_str(char *buffer)
{
  int number_str;
  number_str = atoi(buffer);
  number_str = number_str * 2;
  sprintf(buffer, "%d", number_str);
} /* double_the_number_str */

void run_server()
{
  int my_socket;
  int listener;
  int flag;
  struct sockaddr_in addr;
  int buffer_lenght = 1024;
  char buffer[1024];
  int bytes_read;
  int status;

  printf("[INFO] Create a server socket file descriptor\n");
  listener = socket(AF_INET, SOCK_STREAM, 0);
  if(listener < 0)
  {
    perror("socket");
    exit(1);
  }

  printf("[INFO] Set the socket option\n");  
  addr.sin_family = AF_INET;
  addr.sin_port = htons(3425);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);

  printf("[INFO] Bind the socket to the address\n");
  if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
  {
    perror("bind");
    exit(2);
  }
  printf("[INFO] Start listening for new connection\n");
  listen(listener, 1);
   
//  while(1)
//  {
    my_socket = accept(listener, NULL, NULL);
    if(my_socket < 0)
    {
      perror("accept");
      exit(3);
    }
    printf("[INFO] Accepted new connection\n");
//    while(1)
//    {
      bytes_read = recv(my_socket, buffer, 1024, 0);
      if(bytes_read <= 0)
      {
        printf("[INFO] Not received\n");
      }
      
      flag = check_message(buffer);
      if (flag == STR_IS_STR)
      {
        for(int i = 0; i < bytes_read; i++)
        {
          buffer[i] = toupper(buffer[i]);
        }
      }
      if (flag == STR_IS_NUM)
      {
        double_the_number_str(buffer);
      }
      status = send(my_socket, buffer, bytes_read, 0);
      printf("[INFO] Sent %d bytes of %s\n", bytes_read, buffer);
//    }
    close(my_socket);
 // }
}


void run_client()
{
  int my_socket;
  struct sockaddr_in address;
  char buffer[BUFFER_LENGHT];
  char message[BUFFER_LENGHT];

  
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
  scanf("%[^\n]s", message);
    
  send(my_socket, message, sizeof(message), 0);
  recv(my_socket, buffer, sizeof(message), 0);

  printf("Answer from server: %s\n", buffer);

}
