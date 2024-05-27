
/*
  Name:   main.c

  Purpose:  Check if triangle can be formed with the given values of angles

*/

#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"

int main(int argc, char **argv)
{
  int first_angle;
  int second_angle;
  int third_angle;

  printf("Enter triangle first angle (degrees): ");
  scanf("%d", &first_angle);
  printf("Enter triangle second angle (degrees): ");
  scanf("%d", &second_angle);
  printf("Enter triangle third angle (degrees): ");
  scanf("%d", &third_angle);

  if ( triangle_angles(first_angle, second_angle, third_angle)) 
  {
    printf("Valid triangle");
  }
  else 
  {
    printf("Invalid triangle");
  }
  
  return 0;
} /* main */
