/*
  Name:      string_manipulation.c

  Purpose:   Contain fuctions for working with strings using pointer arithmetics
*/
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "string_manipulation.h"

/*
  Name:     s_len

  Purpose:  Compute lenght of a string

  Params:   IN  str    - the input string

  Returns:  Lenght of a string
*/
int s_len(const char* str)
{
  int str_len = 0;

  while(*str != '\0')
  {
    str_len++;
    str++;
  }

  return str_len;
} /* s_len */

/*
  Name:     find_char

  Purpose:  Find an address of the first occurrence of character in a string

  Params:   IN  letter - the input letter 
            IN  str    - the input string

  Returns:  Address of the first occurrence of character in a string
*/
char* find_char(const char letter, char* str, int str_len)
{
  int i;
  
  for(i = 0; i < str_len; i++)
  {
    if (*str != letter)
    {
      str++;
    }
    else
    {
      return str;
    }
    
  }

  return NULL;
}
/*
  Name:     trim_vowel

  Purpose:  remove vowels from a string

  Params:   IN  input  - the input string 
            OUT output - the output string without vowels

*/
void trim_vowel(char* input, char* output)
{
  while(*input != '\0')
  {
    if ((*input != 'a') &&
        (*input != 'o') &&
        (*input != 'u') &&
        (*input != 'i') &&
        (*input != 'e') &&
        (*input != 'A') &&
        (*input != 'O') &&
        (*input != 'U') &&
        (*input != 'I') &&
        (*input != 'E'))
    {
      *output++ = *input;
    }
    input++;
  }
  *output = '\0';
}

/*
  Name:     is_palindrome

  Purpose:  Check if input string is palindrome

  Params:   IN  input  - the input string 

  Returns:  "true" if string is palindrome or "false" if not
*/
int is_palindrome(const char* input)
{
  int i;
  int str_len = s_len(input);

  for(i = 0; i < str_len/2; i++)
  {
    if (*(input + i) != *(input + str_len - i - 1))
    {
      return false;
    }
  }
  return true;
} /* is_palindrome */
