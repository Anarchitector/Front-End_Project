/*
  Name:       main.c

  Purpose:    The program counts alphabets, numbers and special symbols in a string
  
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "count_symbols.h"

#define MAX_LENGHT 200

int main()
{
  char my_string[MAX_LENGHT];

  printf("Enter your string: ");
  scanf("%s", my_string);

  printf("Alphabet is: %d\n", count_alphabet(my_string));
  printf("Numbers is: %d\n", count_numbers(my_string));
  printf("Specials is: %d\n", count_specials(my_string));

  return 0;
}
