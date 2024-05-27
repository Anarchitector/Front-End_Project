/*
  Name:        array_processing.h
                                                                           
  Purpose:     File contains declaration of functions described in array_processing.c                        
                                                                           
*/

#ifndef ARRAY_PROCESSING_H_INCLUDED
#define ARRAY_PROCESSING_H_INCLUDED

#include <stdbool.h>

typedef struct
{
  int min;
  int max;
} min_max;

int find_largest_element(int *numbers, int max_elements);
void display_using_recursion(int *numbers, int array_num);
void find_min_max(int *numbers, int max_elements, min_max *min_max_num);
bool find_duplicated(int *numbers, int max_elements);
void print_unique(int *arr, int* freq, int size);

#endif // ARRAY_PROCESSING_H_INCLUDED
