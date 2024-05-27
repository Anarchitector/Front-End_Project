/*
  Name:    check_eligibility.c

  Purpose: to find the eligibility of admission for a professional course based on the following criteria:
           - Marks in Maths >= 65
           - Marks in Phy >= 55
           - Marks in Chem >= 50
           - Total Maths + Phy + Chem >=180 or total in Math and Phy >=140.

*/

#include <stdio.h>

#include "check_eligibility.h"

int main()
{
   int Math;
   int Phy;
   int Chem;

   printf("Enter your Math grade : ");
   scanf("%d",&Math);
   printf("Enter your Physics grade : ");
   scanf("%d",&Phy);
   printf("Enter your Chemistry grade : ");
   scanf("%d",&Chem);

   if ( check_eligibility(Math, Phy, Chem) ) printf("You are eligible for admission\n");
   else printf("Your are not eligible for admission\n");

     return 0;
}
