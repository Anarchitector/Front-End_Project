/*
  Name:       count_symbols.c

  Purpose:    Contain functions that counts alphabets, numbers and special symbols in a string
  
*/

#include <ctype.h>
#include <string.h>

/*
  Name:     count_alphabet

  Purpose:  Count the number of alphabets symbols

  Params:   IN    str   - character string

  Returns:  number of the alphabet symbols
*/
int count_alphabet(char* str)
{
  int cnt = 0;
  int len; 
  int i;

  len = strlen(str);

  for (i = 0; i < len; i++)
  {
    if (((str[i] >= 'A') && (str[i] <= 'Z')) || 
       ((str[i] >= 'a') && (str[i] <= 'z')) )
    {
      cnt++;
    }
  }

  return cnt;
};


/*
  Name:     count_numbers

  Purpose:  Count the number of number symbols

  Params:   IN    str   - character string

  Returns:  number of the number symbols
*/
int count_numbers(char* str)
{
  int cnt = 0;
  int len;
  int i;

  len = strlen(str);
  for (i = 0; i < len; i++)
  {
    if ((str[i] >= '0') && (str[i] <= '9'))
    {
      cnt++;
    }
  }

  return cnt;
}; /* count_numbers */


/*
  Name:     count_specials

  Purpose:  Count the number of special symbols (without space)

  Params:   IN    str   - character string

  Returns:  number of the special symbols
*/
int count_specials(char* str)
{
  int cnt = 0;
  int len;
  int i;
  
  len = strlen(str);

  for(i = 0; i < len; i++)
  {
    if (((str[i] >= '!') && (str[i] <= '/')) || 
       ((str[i] >= ':') && (str[i] <= '@')) || 
       ((str[i] >= '[') && (str[i] <= '\'')) || 
       ((str[i] >= '{') && (str[i] <= '~')))
    {
      cnt++;
    }
  }

  return cnt;
}; /* count_specials */
