/*
  Name:      find_in_file.c

  Purpose:   contain functions to add or replace a word in a text file  
*/

#include <string.h>
#include <stdbool.h>
#include "find_in_file.h"

/*
  Name:     is_word_in_file

  Purpose:  Search a word in a file

  Params:   IN  filename - the name of the text file
            IN  word     - the word to find it in a text file
  
  Returns:  'true' if word is found or 'false' if not
*/
int is_word_in_file(char* filename, const char *word)
{
  FILE *fptr;
  char str[BUFFER_SIZE];
  bool flag = false;

  fptr = fopen(filename, "r");
  rewind(fptr);
  while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
  {
    if (strstr(str, word) != NULL)
    {
      flag = true;
      break;
    }
  }
  fclose(fptr);
  return flag;
}

/*
  Name:     replace_word

  Purpose:  Replace the word by another word

  Params:   IN  filename - the name of file where replacement take place
            IN  old_word - word to be replaced in a text file
            IN  new_word - replacement word
  
  Returns:  State SUCCESS or FAULT
*/
int replace_word(char *filename, const char *old_word, const char *new_word)
{
  FILE *fptr;
  FILE *ftmp;

  char *pos;
  char tmp[BUFFER_SIZE];
  char buffer[BUFFER_SIZE];
  int index = 0;
  int old_word_len;

  fptr  = fopen(filename, "r");
  if (fptr == NULL)
  {
    printf("\nUnable to open source file.\n");
    return FAULT;
  }

  ftmp = fopen("replace.tmp", "w");
  if (ftmp == NULL)
  {
    printf("\nUnable to open temporary file.\n");
    return FAULT;
  }

  old_word_len = strlen(old_word);
  rewind(fptr);

  while ((fgets(buffer, BUFFER_SIZE, fptr)) != NULL)
  {
    if ((pos = strstr(buffer, old_word)) != NULL)
    {
      strcpy(tmp, buffer);
      index = pos - buffer;
      buffer[index] = '\0';
      strcat(buffer, new_word);
      strcat(buffer, tmp + index + old_word_len);
    }
    fputs(buffer, ftmp);
  }
  
  fclose(fptr);
  fclose(ftmp);

  remove(filename);
  rename("replace.tmp", filename);

  return SUCCESS;
} /* replace_word */

/*
  Name:     update_file

  Purpose:  Add the input word to the end of file 

  Params:   IN  filename - the name of text file 
            IN  word     - word to add to the file
  
  Returns:  State SUCCESS or FAULT
*/
int update_file(char *filename, char *word)
{
  FILE *fptr;

  fptr = fopen(filename, "a");
  if ( fptr == NULL)
  {
    return FAULT;
  }

  if (!feof(stdin))
  {
    fprintf(fptr, "\n%s", word);
  }
  fclose(fptr);
  
  return SUCCESS;
} /* update_file */

/*
  Name:     compare_files

  Purpose:  Compare the words in files 

  Params:   IN  filename     - the name of text file 
            IN  filename_exp - the name of file expected result
  
  Returns:  State SUCCESS or FAULT
*/
int compare_files(char *filename, char *filename_exp)
{
  FILE *fptr_file;
  FILE *fptr_exp;

  char str_file[BUFFER_SIZE];
  char str_exp[BUFFER_SIZE];

  int result;

  fptr_file = fopen(filename, "r");
  if (fptr_file == NULL)
  {
    printf("File %s could not be opened\n", filename);
    return FAULT;
  }
  fptr_exp = fopen(filename_exp, "r");
  if (fptr_exp == NULL)
  {
    printf("File %s could not be opened\n", filename_exp);
    return FAULT;
  }

  rewind(fptr_file);
  rewind(fptr_exp);

  while ((fgets(str_file, BUFFER_SIZE, fptr_file)) != NULL)
  {
    fgets(str_exp, BUFFER_SIZE, fptr_exp);
    if (!(strcmp(str_file, str_exp)))
    {
      result = SUCCESS;
    }
    else
    {
      result = FAULT;
      break;
    }
    
  }
  fclose(fptr_file);
  fclose(fptr_exp);

  return result;
} /* compare_files */
