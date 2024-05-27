
/*
  Name:        temperature.c

  Purpose:     File contain functions which convert
               Fahrenheit temperature to Celsius

*/

#include "temperature.h"

/*
      Name:     convert_fahrenheit_to_celsius

      Purpose:  Function return the value of perimeter of rectangle

      Params:   IN    fahrenhiet_temperature - The value of the temperature in fahrenheit degree

      Returns:  Value of a temperature in celsius degree
*/
float convert_fahrenheit_to_celsius(int fahrenheit_temperature)
{
  return (5 / 9 * (fahrenheit_temperature - 32));
} /* convert_fahrenheit_to_celsius */
