/*
  Name:     total_amount.c

  Purpose:  File contains the function which computed
            total amount (cents) according to the elapsed time (minutes)
*/

#include <stdio.h>

#define LAST_FREE_MINUTE     50
#define PRICE_199_MINUTES    2980
#define PRICE_399_MINUTES    5980
#define PRICE_499_MINUTES    6980

/*
  Name:    get_total_amount

  Purpose: Compute total amount according to the elapsed time

  Param:   IN  - minutes - The value of the elapsed
           OUT - amount  - The computed value of amount
  
  Result:  Total amount (cents) according to the elapsed time (minutes)
*/
int get_total_amount(int minutes)
{
  int amount;
  
  if (minutes <= LAST_FREE_MINUTE)
  {
    amount = 0;
  }
  else if( minutes > LAST_FREE_MINUTE && minutes <= 199)
  {
    amount = (minutes - LAST_FREE_MINUTE) * 20;
  }
  else if( minutes >= 200 && minutes <= 399)
  {
    amount = (minutes - 199) * 15 + PRICE_199_MINUTES;
    printf("\n%d\n", amount);
  }
  else if( minutes >= 400 && minutes <= 499)
  {
    amount = (minutes - 399) * 10 + PRICE_399_MINUTES;
  }
  else if ( minutes >= 500 )
  {
    amount = (minutes - 499) * 5 + PRICE_499_MINUTES;
  } 
  return amount;
} /* get_total_amount */
