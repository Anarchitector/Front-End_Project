/*
  Name:       main.c

  Purpose:    to replace the word in file or to add if the word doesn't exist 
  
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "find_in_file.h"

int main()
{
  char old_word[100];
  char new_word[100];
  char *filename = "text_file.txt";

  printf("Enter word to replace: ");
  scanf("%s", old_word);

  if (is_word_in_file(filename, old_word))
  {
    printf("Replace '%s' with: ", old_word);
    scanf("%s", new_word);

    if(replace_word(filename, old_word, new_word) == SUCCESS)
    {
      printf("\nSuccessfully replaced all occurrences of '%s' with '%s'.", old_word, new_word);
    }
    else
    {
      printf("Unable to replace the word in file.");
    }
  }
  else
  {
    if (update_file(filename, old_word) == SUCCESS)
    {
      printf("\n'%s' succesfully added to the file.", old_word);
    }
    else
    {
      printf("File could not be opened\n");
    }
  }

  return 0;
} /* main */
