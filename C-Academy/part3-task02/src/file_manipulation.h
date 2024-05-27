/*
  Name:        file_manipulation.h
                                                                           
  Purpose:     File contains declaration of functions described in file_manipulation.c                        
                                                                           
*/

#ifndef FILE_MANIPULATION_H_INCLUDED
#define FILE_MANIPULATION_H_INCLUDED

int words_count(FILE *fptr);
int char_count(FILE *fptr);
int lines_count(FILE *fptr);
int digits_count(FILE *fptr);
void symbols_count(FILE *fptr, int *word_cnt, int *char_cnt, int *lines_cnt, int *digits_cnt);

#endif // FILE_MANIPULATION_H_INCLUDED
