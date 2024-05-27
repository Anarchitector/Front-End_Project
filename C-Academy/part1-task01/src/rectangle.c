
/*
  Name:   rectangle.c

  Purpose:  The file contains functions that 
            computes area and perimeter of a rectangle

*/

#include "rectangle.h"

/*
      Name:        rectangle_area

      Purpose:     Function return the value of area of rectangle

      Params:      IN    lenght   - The lenght of a rectangle
                   IN    width    - The width of a rectangle

      Returns:  Value of a rectangle area or -1 
                if one of the input parameters are less or equal than zero
*/
int rectangle_area(int length, int width)
{
  if ((length <= 0) || (width <= 0))
  {
    return -1;
  }

  return (length * width);
} /* rectangle_area */


/*
      Name:        rectangle_perimeter

      Purpose:     Function return the value of perimeter of rectangle

      Params:      IN    lenght   - The lenght of a rectangle
                   IN    width    - The width of a rectangle

      Returns:  Value of a rectangle perimeter or -1 
                if one of the input parameters are less or equal than zero
*/
int rectangle_perimeter(int length, int width)
{
  if ((length <= 0) || (width <= 0))
  {
    return -1;
  }

  return (length + width) * 2;
} /* rectangle_perimeter */
