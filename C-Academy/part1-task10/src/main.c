/*
  Name:   main.c

  Purpose:  compute the sum of the first `N` natural numbers using 'for', 'while',
            the sum of even numbers and odd numbers

*/

#include <stdio.h>
#include <stdlib.h>
#include "compute_the_sum.h"

int main()
{
    int num;

    printf("Enter an integer number : ");
    scanf ("%d", &num);

    printf("The sum of the first %d natural numbers using for : %d", num, get_sum_of_natural_num_for(num));
    printf("\n");
    printf("The sum of the first %d natural numbers using while : %d", num, get_sum_of_natural_num_while(num));
    printf("\n");
    printf("The sum of the first %d natural even numbers using for : %d", num, get_sum_of_natural_even_num(num));
    printf("\n");
    printf("The sum of the first %d natural odd numbers using while : %d", num, get_sum_of_natural_odd_num(num));


    return 0;
} /* main */

