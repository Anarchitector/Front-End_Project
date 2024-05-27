/*
  Name:      main.c

  Purpose:   The program read the data for two persons and output the person with the greater age

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "greater_age.h"

int main()
{
  person john_carmack;
  john_carmack.name = "John Carmack";
  john_carmack.age = 50;

  person john_romero;
  john_romero.name = "John Romero";
  john_romero.age = 52;

  person* result;

  result = whose_age_is_greater(&john_carmack, &john_romero);
  printf("%s - %d", result->name, result->age);
  return 0;
} /* main */
