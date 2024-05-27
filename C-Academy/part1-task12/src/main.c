/*
  Name: main.c
  
  Purpose: Entering number of minutes used by an user and computes the total amount (in cents) to pay. 
           The charged is determined as follows:

           - the first 50 minutes are free of charge;
           - from  51 up to 199 the user pays 20 cents per minute;
           - from 200 up to 399 the user pays 15 cents per minute;
           - from 400 up to 499 the user pays 10 cents per minute;
           - from 500 the user pays 5 cents per minute;
*/

#include <stdio.h>
#include <stdlib.h>

#include "total_amount.h"

int main()
{
    int minutes;

    printf("Enter the time (minutes) : ");
    scanf("%d", &minutes);

    printf("Your total amount is %d cents", get_total_amount(minutes));


    return 0;
}
