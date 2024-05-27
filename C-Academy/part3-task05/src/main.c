/*
  Name:       main.c

  Purpose:    To convert the the alphabet characters to uppercase and 
              doubled the number if received characters are only digits
  
*/
#include <stdio.h>
#include <stdlib.h>
#include "server_func.h"

int main()
{
  int user_input;

  printf("\n********************** MAIN MENU **********************\n");
  printf("\n1. Server");
  printf("\n2. Client");
  printf("\n\nChoose your destiny: ");
  do
  {
    scanf("%d", &user_input);
  } while ((user_input < 0) || (user_input > 2));
  
  if (user_input == 1)
  {
    run_server();
  }

  if (user_input == 2)
  {
    run_client();
  }

  return 0;
} /* main */
