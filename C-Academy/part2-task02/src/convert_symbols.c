/*
  Name:      convert_symbols.c

  Purpose:   Converting symbols  
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 10

/*
  Name:     lowercase_to_uppercase

  Purpose:  Converting lowercase symbols to uppercase

  Params:   IN/OUT  my_string - the string of different symbols. After convertion 
                                lowercase alphabet symbols become uppercase.

  Returns:  The string where lowercase alphabet symbols were converted to uppercase
*/
char* lowercase_to_uppercase(char* my_string)
{
  int cnt;

  for(cnt = 0; cnt < MAX_ELEMENTS; cnt++)
  {
    my_string[cnt] = toupper(my_string[cnt]);
  }
  
  return my_string;
} /* lowercase_to_uppercase */
