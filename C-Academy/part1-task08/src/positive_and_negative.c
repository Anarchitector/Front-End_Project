/*
  Name:     number_determining.c

  Purpose:  File contains functions that are determines whether
            the number is positive, negative or zero

*/


/*
  Name:    number_determining_if

  Purpose: Function determines the number using if selection

  Param:   IN   number - number which will be determine

  Result:  Number is positive, negative or zero
*/
 int number_determining_if(int number)
{
  int result;

  if (number > 0) 
  {
    result = 1;
  }
  else if (number < 0)
  {
    result = -1;
  }
  else
  {
    result = 0;
  }

  return result;
} /* number_determining_if */


/*
  Name:    number_determining_switch

  Purpose: Function determines the number using switch selection

  Param:   IN   number - integer which will be determine

  Result:  Number is positive, negative or zero
*/
int number_determining_switch(int number)
{
  int result;

  switch (number > 0)
  {
    case 1:
      result = 1;
      break;
    case 0:
      switch (number < 0)
      {
        case 1:
          result = -1;
          break;
        case 0:
          result = 0;
          break;
      }
    break;
  }

return result;
}/* number_determining_switch */
