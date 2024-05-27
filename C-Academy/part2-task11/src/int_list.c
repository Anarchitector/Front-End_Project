#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
  Name:     read_integers

  Purpose:  read the integers from the user

  Params:   OUT  int_ptr  - the input string 
            IN   num      - number of integers to introduce by user

  Return:   Nothing
*/
void read_integers(int* int_ptr, int num)
{
  int i;
  
  for(i = 1; i <= num; i++)
  {
    printf("Enter element %d : ", i);
    scanf("%d", int_ptr++);
  }

  printf("\n");
} /* read_integers */

/*
  Name:     list_integers

  Purpose:  print the integers from array

  Params:   IN   int_ptr - array of integers
            IN   num     - number of integers in array
  
  Return:   Nothing
*/
void list_integers(int* int_ptr, int num)
{
  int *i;
  
  printf("Integer list: ");
  for(i = int_ptr; i < int_ptr + num; i++)
  {
    printf("%d ", *i);
  }
  printf("\n");
} /* list_integers */

/*
  Name:     list_integers_reversed

  Purpose:  print the integers from array in reversed order

  Params:   IN   int_ptr - array of integers
            IN   num     - number of integers in array

  Return:   Nothing
*/
void list_integers_reversed(int* int_ptr, int num)
{
  int *i;

  printf("Integer list (reversed): ");
  for(i = int_ptr + num - 1; i >= int_ptr; i--)
  {
    printf("%d ", *i);
  }
  printf("\n");
} /* list_integers_reversed */

/*
  Name:     list_integers_ascending

  Purpose:  print the integers from array in ascending order

  Params:   IN   int_ptr   - array of integers
            OUT  asc_order - array of integers in ascending order
            IN   num       - number of integers in array

  Return:   Nothing
*/
void list_integers_ascending(int* int_ptr, int* asc_order, int num)
{
  int i;
  int j;
  int temp;

  printf("Integer list (sorted): ");

  for(i = 0; i < num; i++)
  {
    *(asc_order+i) = *(int_ptr+i);
  }

  for(i = 0; i < num; i++)
  {
    for(j = i + 1; j < num; j++)
    {
      if (*(asc_order + j) < *(asc_order + i))
      {
        temp = *(asc_order + i);
        *(asc_order + i) = *(asc_order + j);
        *(asc_order + j) = temp;
      }
    }
  }

  for(i = 0; i < num; i++)
  {
    printf("%d ", *(asc_order + i));
  }

  printf("\n");
}
