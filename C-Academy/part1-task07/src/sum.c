/*
  Name:        sum.c

  Purpose:     File contain function that reads a long and prints the sum of its digits.

*/

#include <stdlib.h>
#include <math.h>

/*
  Name:     sum_of_digits

  Purpose:  Compute the sum of long number digits

  Params:   IN    number  - The value of the long number

  Returns:  Sum of long number digits
*/
long sum_of_digits(long number)
{
  int sum = 0;

  while (number != 0)
  {
    sum += number % 10;
    number /= 10;
  }
  return abs(sum);
}/* sum_of_digits */
