
/*
  Name:   main.c

  Purpose:  Convert Fahrenheit temperature to Celsius

*/

#include <stdio.h>
#include <stdlib.h>
#include "temperature.h"

int main(int argc, char **argv)
{
  int fahrenheit;

  printf("Enter temperature in fahrenheit (degrees): ");
  scanf("%d", &fahrenheit);
  
  printf("Temperature in Celsius is: %.2f \n", convert_fahrenheit_to_celsius(fahrenheit));
  

  return 0;
} /* main */
