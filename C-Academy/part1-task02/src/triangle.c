
/*
  Name:   triangle.c

  Purpose:  File contains functions which check if triangle can be formed

*/

#include "triangle.h"


/*
      Name:     triangle_angles

      Purpose:  Function check if triangle can be formed

      Params:   IN    first_angle - The value of the first angle of triangle
                IN    second_angle - The value of the second angle of triangle
                IN    third_angle - The value of the third angle of triangle

      Returns:  true or false
*/
bool triangle_angles(int first_angle, int second_angle, int third_angle)
{
  if ((first_angle <= 0) || (second_angle <= 0) || (third_angle <= 0))
  {
    return false;
  }

  if (first_angle + second_angle + third_angle != 180)
  {
    return false;
  }

  return true;
} /* triangle_angles */
