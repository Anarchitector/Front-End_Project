#include <stdio.h>
#include <stdlib.h>
#include "file_manipulation.h"

int main()
{
    FILE *fptr;
    int word_cnt = 0;
    int char_cnt = 0;
    int lines_cnt = 1;
    int digits_cnt = 0;

    fptr = fopen("text_file.txt","r");
    if(fptr==NULL)
    {
      printf(" File does not exist or can not be opened.");
    }
    else
    {
      symbols_count(fptr, &word_cnt, &char_cnt, &lines_cnt, &digits_cnt);
      printf("\nWords: %d\n", word_cnt);
      printf("\nCharacters: %d\n",char_cnt);
      printf("\nLines: %d\n",lines_cnt);
      printf("\nDigits: %d\n",digits_cnt);
    }
    fclose(fptr);

    return 0;
}
