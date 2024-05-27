#ifndef STUDENTS_H_INCLUDED
#define STUDENTS_H_INCLUDED

typedef struct
{
  char name[20];
  char surname[20];
  int grade;
} student;

void enter_the_data(student *list, int max);
void display_the_list_of_students(student *list, int num);
void display_the_promoted_student(student *list, int max);
void sort_by_descending(student *list, int max);
float calculate_the_mean(student *list, int num);

#endif // STUDENTS_H_INCLUDED
