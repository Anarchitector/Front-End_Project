/*
  Name:        math_operations.c

  Purpose:     File contain functions which compute sum, difference, product, division,
               modul, average, minimum and maximum of two values

*/


/*
  Name:     sum

  Purpose:  Compute sum of two numbers

  Params:   IN    first_term  - The value of the first input number
            IN    second_term - The value of the second input number

  Returns:  Sum of two input numbers
*/
int sum(int first_term,
        int second_term)
{
  return (first_term + second_term);
} /* sum */


/*
  Name:     difference

  Purpose:  Compute difference of two numbers

  Params:   IN    minuend  - The value of the first input number
            IN    subtrahend - The value of the second input number

  Returns:  Difference of two input numbers
*/
int difference(int minuend,
               int subtrahend)
{
  return (minuend - subtrahend);
} /* difference */


/*
  Name:     product

  Purpose:  Compute product of two numbers

  Params:   IN    multiplier    - The value of the first input number
            IN    multiplicand  - The value of the second input number

  Returns:  Product of two input numbers
*/
int product(int multiplier, 
            int multiplicand)
{
  return (multiplier * multiplicand);
} /* product */


/*
  Name:     division

  Purpose:  Compute division of two numbers

  Params:   IN    dividend  - The value of the first input number
            IN    divisor   - The value of the second input number

  Returns:  Division of two input numbers. If divisor is zero the function return -1
*/
float division(int dividend,
               int divisor)
{
  if (divisor == 0 ) 
  {
    return -1;
  }
  return (dividend / (float)divisor);
} /* division */


/*
  Name:     modul

  Purpose:  Compute modulus of two numbers

  Params:   IN    first_number    - The value of the first input number
            IN    second_number   - The value of the second input number

  Returns:  Modulus of two input numbers. If second_number is zero the function return -1
*/
int modul(int first_number,
          int second_number)
{
  if (second_number == 0 ) 
  {
    return -1;
  }
  return (first_number % second_number);
} /* modul */


/*
  Name:     average

  Purpose:  Compute average value of two numbers

  Params:   IN    first_number    - The value of the first input number
            IN    second_number   - The value of the second input number

  Returns:  Average value of two input numbers.
*/
float average(int first_number, 
              int second_number)
{
  return ((first_number + (float)second_number)/2);
} /* average */


/*
  Name:     minimum

  Purpose:  Compute the minimum value of two numbers

  Params:   IN    first_number    - The value of the first input number
            IN    second_number   - The value of the second input number

  Returns:  Minimum value of two input numbers.
*/
int minimum(int first_number,
            int second_number)
{
  return ((first_number < second_number) ? first_number : second_number);
} /* minimum */


/*
  Name:     maximum

  Purpose:  Compute the maximum value of two numbers

  Params:   IN    first_number    - The value of the first input number
            IN    second_number   - The value of the second input number

  Returns:  Maximum value of two input numbers.
*/
int maximum(int first_number, 
            int second_number)
{
  return ((first_number > second_number) ? first_number : second_number);
} /* maximum */
