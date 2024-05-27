/*
  Name:      main.c

  Purpose:   The program convert lowercase alphabet symbols to uppercase in a string

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert_symbols.h"

#define MAX_LENGHT 200

int main()
{
  char my_string[MAX_LENGHT];

  printf("Enter the string: ");
  scanf("%s", my_string);
  printf("Converted string: %s", lowercase_to_uppercase(my_string));

  return 0;
} /* main */
