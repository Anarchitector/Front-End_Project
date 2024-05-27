/*
  Name:       main.c

  Purpose:    The program calculates sum of two fractions.
              Each fraction is a structure that contain 
              two integer variables: num (numerator) and den (denominator)
  
*/

#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"

int main()
{
    fraction frac1;
    fraction frac2;
    fraction result;

    printf("Enter the numerator of fraction1: ");
    scanf("%d", &frac1.num);
    printf("Enter the denominator of fraction1: ");
    scanf("%d", &frac1.den);
    printf("Enter the numerator of fraction2: ");
    scanf("%d", &frac2.num);
    printf("Enter the denominator of fraction2: ");
    scanf("%d", &frac2.den);

    printf("Fraction1 is :%d/%d\n", frac1.num, frac1.den);
    printf("Fraction2 is :%d/%d\n", frac2.num, frac2.den);
    add_two_fractions(&frac1, &frac2, &result);
    if (result.den == 0) 
    {
      printf("Error - at least one of denominators is zero");
    }
    printf("The sum of two fractions is: %d/%d", result.num, result.den);
  
    return 0;
} /* main */
