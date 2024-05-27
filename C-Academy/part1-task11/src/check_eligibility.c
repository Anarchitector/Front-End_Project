/*
  Name:        check_eligibility.c

  Purpose:     File contain function that check if student allowed to course or not

*/

#include "check_eligibility.h"


/*
  Name:     check_eligibility

  Purpose:  Check if the student is allowed to course

  Params:   IN    Math  - The Math grade
            IN    Phy   - The Physics grade
            IN    Chem  - The Chemistry grade

  Returns:  boolean values - true if student is allowed to course,
                             false if not
*/
bool check_eligibility(int Math, int Phy, int Chem)
{
    if ((Math >= 65) && (Phy >= 55) && (Chem >= 50))
   {
        if((Math + Phy + Chem) >= 180 || (Math + Phy) >= 140)
        {
          return true;
        }
        else
        {
          return false;
        }

   }
   else
   {
        return false;
   }

}
