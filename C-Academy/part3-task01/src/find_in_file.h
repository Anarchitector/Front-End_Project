/*
  Name:        find_in_file.h
                                                                           
  Purpose:     File contains declaration of functions described in find_in_file.c                        
                                                                           
*/
#include <stdio.h>
#include <stdlib.h>

#ifndef FIND_IN_FILE_H_INCLUDED
#define FIND_IN_FILE_H_INCLUDED

#define BUFFER_SIZE 1000

typedef enum
{
  SUCCESS,
  FAULT
} status_op;

int is_word_in_file(char *filename, const char *word);
int replace_word(char *filename, const char *old_word, const char *new_word);
int update_file(char *filename, char *word);
int compare_files(char *filename, char *filename_exp);

#endif // FIND_IN_FILE_H_INCLUDED
