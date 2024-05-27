#include <stdio.h>
#include "students.h"


int main()
{
  student list[4];
  int num;

  printf("Enter number of records: ");
  scanf("%d", &num);
  enter_the_data(list, num);
  sort_by_descending(list, num);
  printf("\nList of students:");
  display_the_promoted_student(list, num);

  return 0;
}
