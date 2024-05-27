/*
  Name:   main.c

  Purpose:  Choose the math operation and perform it with two numbers

*/

#include <stdio.h>
#include <stdlib.h>
#include "math_operations.h"

int main()
{
  int first_number;
  int second_number;
  char math_op;

  printf("Choose the math operation: ");
  scanf("%c", &math_op);

  printf("Enter first number: ");
  scanf("%d", &first_number);
  printf("Enter second number: ");
  scanf("%d", &second_number);

  switch(math_op)
  {
    case '+' :
      printf("The sum of entered numbers is : %d", sum(first_number, second_number));
      break;
    case '-' :
      printf("The difference of entered numbers is : %d", difference(first_number, second_number));
      break;
    case '*' :
      printf("The product of entered numbers is : %d", product(first_number, second_number));
      break;
    case '/' :
      printf("The division of entered numbers is : %.2f", division(first_number, second_number));
      break;
    case '%' :
      printf("The modulus of entered numbers is : %d", modul(first_number, second_number));
      break;
    case 'a' :
      printf("The average of entered numbers is : %.2f", average(first_number, second_number));
      break;
    case '<' :
      printf("The minimum of entered numbers is : %d", minimum(first_number, second_number));
      break;
    case '>' :
      printf("The maximum of entered numbers is : %d", maximum(first_number, second_number));
      break;
    default :
      printf("Entered operation was incorrect");
      break;
  }

    return 0;
} /* main */
