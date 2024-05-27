/*
  Name:      file_manipulation.c

  Purpose:   contain function to count words, characters, lines and digits in a text file  
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
  Name:     symbols_count

  Purpose:  Count the number of words, characters, lines and digits in a text file

  Params:   IN  fptr - the pointer to the text file
  
  Returns:  Number of words, characters, lines and digits in a text file
*/
void symbols_count(FILE *fptr, int *word_cnt, int *char_cnt, int *lines_cnt, int *digits_cnt)
{
  char ch;
  int flag = 0;
  int i = 0;

  rewind(fptr);
  ch = fgetc(fptr);

  while (ch != EOF)
  {
    *char_cnt += 1;

    if ((ch == ' ') ||
       (ch == '\n') ||
       (ch == '\t') ||
       (ch == '\0'))
    {
      flag = 1;
    }
    else if ((flag == 1) && (isalpha(ch)))
    {
      flag = 0;
      *word_cnt += 1;
    }
    if (ch == '\n')
    {
      *lines_cnt += 1;
    }
    if (isdigit(ch))
    {
      *digits_cnt += 1;
    }
    ch = fgetc(fptr);
  }

  while (!(isalpha(ch)))
  {
    --i;
    fseek(fptr, i, SEEK_END);
    ch = fgetc(fptr);
    if (isalpha(ch))
    {
      *word_cnt += 1;
    }
  }
  
} /* symbols_count */
