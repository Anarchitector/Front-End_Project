/*
  Name:        compute_the_sum.c

  Purpose:     File contain functions which computes the sum of the first `N` natural numbers

*/


/*
  Name:     get_sum_of_natural_num_for

  Purpose:  compute the sum of the first `N` natural numbers

  Params:   IN    num  - The value of the natural number
            OUT   sum  - The sum of the first `N` natural numbers

  Returns:  The sum of the first `N` natural numbers using `for`
*/
int get_sum_of_natural_num_for(int num)
{
  int i;
  int sum = 0;

  for (i = 1; i <= num; i++)
  {
    sum += i;
  }

  return sum;
}/* get_sum_of_natural_num_for */


/*
  Name:     get_sum_of_natural_num_while

  Purpose:  compute the sum of the first `N` natural numbers

  Params:   IN    num  - The value of the natural number
            OUT   sum  - The sum of the first `N` natural numbers

  Returns:  The sum of the first `N` natural numbers using `while`
*/
int get_sum_of_natural_num_while(int num)
{
  int i = 1;
  int sum = 0;

  while(i <= num)
  {
    sum += i;
    i++;
  }

  return sum;
}/* get_sum_of_natural_num_while */


/*
  Name:     get_sum_of_natural_even_num

  Purpose:  compute the sum of the first `N` natural even numbers

  Params:   IN    num  - The value of the natural number
            OUT   sum  - The sum of the first `N` natural even numbers

  Returns:  The sum of the first `N` natural even numbers using `for`
*/
int get_sum_of_natural_even_num(int num)
{
  int i;
  int sum = 0;

  for (i = 1; i <= num; i++)
  {
    if(!(i % 2)) sum += i;
  }

  return sum;
}/* get_sum_of_natural_even_num */


/*
  Name:     get_sum_of_natural_odd_num

  Purpose:  compute the sum of the first `N` natural even numbers

  Params:   IN    num  - The value of the natural number
            OUT   sum  - The sum of the first `N` natural odd numbers

  Returns:  The sum of the first `N` natural odd numbers using `while`
*/
int get_sum_of_natural_odd_num(int num)
{
  int i = 1;
  int sum = 0;

  while(i <= num)
  {
    if(i % 2) sum += i;
    i++;
  }

  return sum;
}
/* get_sum_of_natural_odd_num */
