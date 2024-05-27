#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "students.h"

void enter_the_data(student *list, int num)
{
  int i;
  for (i = 0; i < num; i++)
  {
    printf("\n\nEnter data for record #%d", i + 1);
    printf("\nEnter name : ");
    scanf("%s", list[i].name);
    printf("Enter surname : ");
    scanf("%s", list[i].surname);
    printf("Enter grade : ");
    scanf("%d", &list[i].grade);
  }
}

void display_the_list_of_students(student *list, int num)
{
  int i;

  printf("\n\n| %-7s | %-13s | %-5s |\n", "Name", "Surname", "Grade");
  printf("--------------------------------------\n");
  for (i = 0; i < num; i++)
  {
    printf("| %-7s | %-13s | %-5d |\n", list[i].name, list[i].surname, list[i].grade);
  }
}

void display_the_promoted_student(student *list, int num)
{
  int i;

  printf("\n\n| %-7s | %-13s | %-5s |\n", "Name", "Surname", "Grade");
  printf("--------------------------------------\n");
  for (i = 0; i < num; i++)
  {
    if (list[i].grade > 7)
    {
      printf("| %-7s | %-13s | %-5d |\n", list[i].name, list[i].surname, list[i].grade);
    }
  }
}

void sort_by_descending(student *list, int max)
{
  int i;
  int j;
  student temp;

  for (i = 0; i < max - 1; i++)
  {
    for (j = 0; j < (max - 1 - i); j++)
    {
      if (list[j].grade < list[j + 1].grade)
      {
        temp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = temp;
      }
    }
  }
}

float calculate_the_mean(student *list, int num)
{
  int i;
  float sum = 0.0f;

  for(i = 0; i < num; i++)
  {
    sum += list[i].grade;
  }
  return sum / num;
}
