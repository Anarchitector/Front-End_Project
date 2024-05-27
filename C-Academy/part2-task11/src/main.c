/*
  Name:       main.c

  Purpose:    Manipulation with list of integer values using pointer arithmetics
  
*/
#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

int main()
{
  int num = 0;
  int* int_ptr;
  int* asc_order;

  printf("Enter the number of integer you want to store: ");
  scanf("%d", &num);

  int_ptr = (int*)malloc(num * sizeof(int));
  asc_order = (int*)malloc(num * sizeof(int));

  read_integers(int_ptr, num);
  list_integers(int_ptr, num);
  list_integers_reversed(int_ptr, num);
  list_integers_ascending(int_ptr, asc_order, num);

  free(int_ptr);
  free(asc_order);

  return 0;
}
