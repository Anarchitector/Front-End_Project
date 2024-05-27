/*
  Name:        main.c

  Purpose:     The program reads a number of a day prints the name for the day of the week.

*/

#include <stdio.h>
#include "week_day.h"

int main(int argc, char *argv[])
{
  int day_number;
  char* week_day_list[8] = {"Non-existent day", "Monday", "Tuesday", 
                            "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

  printf("Enter the day number: ");
  scanf("%d", &day_number);

  printf("%s", week_day_list[get_day(day_number)]);

  return 0;
} /* main */
