/*
  Name:        week_day.c

  Purpose:     File contain function that reads a number and 
               return a value for the day of the week if it is from 1 to 7 or 0.

*/

#include "week_day.h"

/*
  Name:     get_day

  Purpose:  

  Params:   IN    Day  - The number of the day

  Returns:  Number of week day or zero if number is incorrect
*/
int get_day(int Day)
{
  
  switch(Day)
    {
    case 1 :
        Day = Monday;
        break;
    case 2 :
        Day = Tuesday;
        break;
    case 3 :
        Day = Wednesday;
        break;
    case 4 :
        Day = Thursday;
        break;
    case 5 :
        Day = Friday;
        break;
    case 6 :
        Day = Saturday;
        break;
    case 7 :
        Day = Sunday;
        break;
    default :
        Day = 0;
        break;
    }
    return Day;
} /* get_day */
