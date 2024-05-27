#define MINUTES_PER_YEAR 525600
#define MINUTES_PER_DAY  1440

/*
  Name:        minutes_to_years.c

  Purpose:     File contain functions which convert the value of minutes to years and remainig days

*/


/*
  Name:     convert_minutes_to_years

  Purpose:  Convert the value of minutes to years

  Params:   IN    minutes  - The value of the minutes

  Returns:  Converted value of years from minutes
*/
int convert_minutes_to_years(long minutes)
{
    return minutes / MINUTES_PER_YEAR;
}/* convert_minutes_to_years */

/*
  Name:     convert_minutes_to_left_over_days

  Purpose:  Convert the value of minutes to number of days less than a year

  Params:   IN    minutes  - The value of the minutes

  Returns:  Converted value of remaining days from minutes
*/
int convert_minutes_to_left_over_days(long minutes)
{
    return ( minutes % MINUTES_PER_YEAR ) / MINUTES_PER_DAY;
}/* convert_minutes_to_left_over_days */
