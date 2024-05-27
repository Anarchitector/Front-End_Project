/*
  Name:      greater_age.c

  Purpose:   contain functions to compute whose age is greater of two persons  
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "greater_age.h"

/*
  Name:     whose_age_is_greater

  Purpose:  compute whose age is greater of two persons

  Params:   IN - first  - the data of first person
            IN - second - the data of second person

  Returns:  the data of person whose age is greater
*/
person* whose_age_is_greater(person* first, person* second)
{
    if(first->age > second->age)
    {
      return first;
    }
    else
    {
      return second;
    }
}
