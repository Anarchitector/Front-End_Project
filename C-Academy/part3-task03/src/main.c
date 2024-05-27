/*
  Name:       main.c

  Purpose:    Processing the lists of students and their grades.
  
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "student_list.h"

int main()
{
  char c;
  student_t stud_input;
  grades_t  grades_input;

  char student_file_name[] = "student.txt";
  char grades_file_name[] = "grades.txt";
  char graduated_file_name[] = "graduated.txt";

  if (check_file(student_file_name) == FILE_NOT_EXIST)
  {
    create_student_file(student_file_name);
  }
  if (check_file(grades_file_name) == FILE_NOT_EXIST)
  {
    create_grades_file(grades_file_name);
  }
  if (check_file(graduated_file_name) == FILE_NOT_EXIST)
  {
    create_graduated_file(graduated_file_name);
  }

  do
  {
    switch(toupper(display_main_menu()))
    {
      case 'H' :
      {
        help_menu();
        break;
      }
      case 'C' :
      { 
        printf("\nAre you sure you want to create a new lists of students and grades?");
        printf("\nYour current lists will be deleted. Y/N? : ");
        do
        {
          scanf(" %c", &c);
        } while (!((c != 'y') || 
                   (c != 'n')));
        if (c == 'y')
        {
          if ((create_student_file(student_file_name) == FILE_CREATED) &&
              (create_grades_file(grades_file_name) == FILE_CREATED))
          {
            printf("\nNew files created successfully");
          }
          else
          {
            printf("\nError : Student list of grade list not created");
          }
        }
        break;
      }
      case 'S' :
      {
        system("clear");
        printf("\nEnter student code : ");
        scanf("%s", stud_input.code);
        printf("Enter first name : ");
        scanf("%s", stud_input.first_name);
        printf("Enter last name : ");
        scanf("%s", stud_input.last_name);
        printf("Enter age : ");
        do
        {
          scanf("%d", &stud_input.age);
        } while (stud_input.age < 0);
        
        switch(add_student(&stud_input, student_file_name))
        {
          case FILE_NOT_EXIST :
          {
            printf("\nFile does not exist or can not be opened.");
            break;
          }
          case STUDENT_ALREADY_EXIST :
          {
            printf("\nThe student already exist.");
            break;
          }
          case STUDENT_ADD_SUCCESSFUL :
          {
            printf("\nThe information about student successfully added to the student list.");
            break;
          }
          case INVALID_VALUE :
          {
            printf("The age is incorrect");
          }
        }
        break;
      }
      case 'G' :
      {
        system("clear");
        printf("\nEnter student code : ");
        scanf("%s", grades_input.code);
        do
        {
          printf("Enter first grade from 1 to 10: ");
          scanf("%d", &grades_input.grade1);
        } while ((grades_input.grade1 < 1) || (grades_input.grade1 > 10 ));
        do
        {
          printf("Enter second grade from 1 to 10:  ");
          scanf("%d", &grades_input.grade2);
        } while ((grades_input.grade2 < 1) || (grades_input.grade2 > 10 ));
        do
        {
          printf("Enter third grade from 1 to 10:  ");
          scanf("%d", &grades_input.grade3);
        } while ((grades_input.grade3 < 1) || (grades_input.grade3 > 10 ));
        switch(add_grades(&grades_input, grades_file_name))
        {
          case FILE_NOT_EXIST :
          {
            printf("File does not exist or can not be opened.\n\n");
            break;
          }
          case STUDENT_ALREADY_EXIST :
          {
            printf("The student already exist.\n\n");
            break;
          }
          case STUDENT_ADD_SUCCESSFUL :
          {
            printf("The grades of student successfully added to the grades list.\n\n");
            break;
          }
        }
        break;
      }
      case 'A' :
      {
        switch(update_graduated_file(graduated_file_name, student_file_name, grades_file_name))
        {
          case STUDENT_ADD_SUCCESSFUL :
          {
            printf("\nThe graduated students added to list succesfully.");
            break;
          }
          case FILE_NOT_EXIST :
          {
            printf("\nError: The lists of students or grades not exists.");
            break;
          }
        }
        break;
      }
      case 'X' :
      {
        exit(0);
        break;
      }
    }
  } while (1);
}
