/*
  Name:      fraction.c

  Purpose:   Sum of two fractions
*/

#include <stdlib.h>
#include "fraction.h"


/*
  Name:     add_two_fractions

  Purpose:  Two fractions addition

  Params:   IN  f1     - the structure which contain first fraction data
            IN  f2     - the structure which contain second fraction data
            OUT result - the result of sum of two fractions

  Returns:  Sum of two fractions
*/
void add_two_fractions(fraction *f1, fraction *f2, fraction *result)
{
  int gcd = 0;

  if((f1->den == 0) || (f2->den == 0))
  {
    result->num = 0;
    result->den = 0;
  }
  else 
  {
    if(f1->num == 0)
    {
      result->num = f2->num;
      result->den = f2->den;
    }
    else if(f2->num == 0)
    {
      result->num = f1->num;
      result->den = f1->den;
    }
    else if (f1->den == f2->den)
    {
      result->num = f1->num + f2->num;
      result->den = f1->den;
    }
    else
    {
      result->num = ((f1->num * f2->den) + (f1->den * f2->num));
      result->den = f1->den * f2->den;
    }

    if ((result->num < 0) && (result->den < 0))
    {
      result->num *= (-1);
      result->den *= (-1);
    }

    gcd = find_gcd(result->num, result->den);
 
    if (gcd != 1)
    {
      result->num /= gcd;
      result->den /= gcd;
    }
  }
} /* add_two_fractions */


/*
  Name:     find_gcd

  Purpose:  Find the GCD of the fraction's numerator and denominator

  Params:   IN  num - fraction's numerator
            IN  den - fraction's denominator

  Returns:  GCD of fraction's numerator and denominator
*/
int find_gcd(int num, int den)
{
  if(num < 0)
  {
    num = abs(num);
  }
  if(den < 0)
  {
    den = abs(num);
  }
  while(num > 0 && den > 0)
  {
    if(num > den)
    {
      num %= den;
    }
    else
    {
      den %= num;
    }
  }
  return num + den;
} /* find_gcd */
