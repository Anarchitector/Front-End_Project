/*
  Name:      student_list.c

  Purpose:   to processing lists of students and grades
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "student_list.h"

/*
  Name:     check_file

  Purpose:  to check at start up if file exist

  Returns:  status exist file or not
*/
status check_file(char *filename)
{
  if (access(filename, F_OK) != -1)
  {
    return FILE_ALREADY_EXIST;
  }
  else
  {
    return FILE_NOT_EXIST;
  }
} /* check_file */

/*
  Name:     display_main_menu

  Purpose:  to display a list of actions

  Returns:  input value by user. If user input is incorrect then nothing happened.
*/
char display_main_menu()
{
  char user_input = 0;
  
  do
  {
    printf("********************************* MAIN MENU *********************************");
    printf("\nh - Information about the program options");
    printf("\nc - create new lists for students and grades");
    printf("\ns - add one student in a list");
    printf("\ng - add grades in grades.txt for one student");
    printf("\na - create a list of graduated students");
    printf("\nx - close the program\n");
    printf("\n> ");
    scanf(" %c", &user_input);
  } while (!((user_input != 'H') ||  
             (user_input != 'C') ||
             (user_input != 'S') ||
             (user_input != 'G') ||
             (user_input != 'A') ||
             (user_input != 'X')));

  return user_input;
} /* display_main_menu */


/*
  Name:     help_menu

  Purpose:  to display a help menu

  Returns:  Nothing
*/
void help_menu()
{
  printf("\n*********************************** HELP MENU ***********************************");
  printf("\nPress 'h' for information about the program options.");
  printf("\nPress 'c' to create a new lists for students and grades. ");
  printf("The old list will be replaced by new.");
  printf("\nPress 's' to add one student in a list. Follow the program requests.");
  printf("\nPress 'g' to add grades in grades.txt for one student. Follow the program requests.");
  printf("\nPress 'a' to create a list of graduated students (average grade is more than 5).");
  printf("\nPress 'x' to close the program.\n");
} /* help menu */

/*
  Name:     add_student

  Purpose:  to add a general information about student to the text fle

  Params:   IN - user_input        - structure of student data
            IN - student_file_name - file name of student list

  Returns:  status of function execution
*/
status add_student(student_t *user_input, char *student_file_name)
{
  FILE *fstudent;
    
  if (user_input->age < 0)
  {
    return INVALID_VALUE;
  }

  fstudent = fopen(student_file_name, "a");
  if (fstudent == NULL)
  {
    return FILE_NOT_EXIST;
  }

  if (is_code_in_file(student_file_name, user_input->code) == STUDENT_ALREADY_EXIST)
  {
    fclose(fstudent);
    return STUDENT_ALREADY_EXIST;
  }
  fprintf(fstudent, "%s|%s|%s|%d\n",
          user_input->code,
          user_input->first_name,
          user_input->last_name,
          user_input->age);
  fclose(fstudent);
  return STUDENT_ADD_SUCCESSFUL;
} /* add_student */


/*
  Name:     create_student_file

  Purpose:  to create to the text file of students data

  Params:   IN - student_file_name - file name of student list

  Returns:  status of function execution
*/
status create_student_file(char *student_file_name)
{
  FILE *fstudent;
  
  fstudent = fopen(student_file_name, "w");
  if (fstudent == NULL)
  {
    return FILE_NOT_CREATED;
  }

  fclose(fstudent);
  return FILE_CREATED;
} /* create_student_file */

/*
  Name:     add_grades

  Purpose:  to add grades of student to the text fle

  Params:   IN - user_input - structure of student data
            IN - grades_file_name - file name of grades list

  Returns:  status of function execution
*/
status add_grades(grades_t *user_input, char *grades_file_name)
{
  FILE *fgrades;
  
  if ((user_input->grade1 < 0) ||
      (user_input->grade2 < 0) ||
      (user_input->grade3 < 0))
  {
    return INVALID_VALUE;
  }

  fgrades = fopen(grades_file_name, "a");
  if (fgrades == NULL)
  {
    return FILE_NOT_EXIST;
  }

  if (is_code_in_file(grades_file_name, user_input->code) == STUDENT_ALREADY_EXIST)
  {
    fclose(fgrades);
    return STUDENT_ALREADY_EXIST;
  }
  fprintf(fgrades, "%s|%d|%d|%d\n",
          user_input->code,
          user_input->grade1,
          user_input->grade2,
          user_input->grade3);
  fclose(fgrades);
  return STUDENT_ADD_SUCCESSFUL;
} /* add_grades */


/*
  Name:     create_grades_file

  Purpose:  to create to the text file of grades

  Params:   IN - grades_file_name - file name of grades list

  Returns:  status of function execution
*/
status create_grades_file(char *grades_file_name)
{
  FILE *fgrades;
  
  fgrades = fopen(grades_file_name, "w");
  if (fgrades == NULL)
  {
    return FILE_NOT_CREATED;
  }

  fclose(fgrades);
  return FILE_CREATED;
}


/*
  Name:     create_graduated_file

  Purpose:  to create to the text file of graduated students data

  Params:   IN - graduated_file_name - file name of graduated students list

  Returns:  status of function execution
*/
status create_graduated_file(char *graduated_file_name)
{
  FILE *fgraduated;
  fgraduated = fopen(graduated_file_name, "w");

  if (fgraduated == NULL)
  {
    return FILE_NOT_CREATED;
  }
  fprintf(fgraduated, "| Student Code |      First Name     |      Last Name       | Average |\n");
  fprintf(fgraduated, "|---------------------------------------------------------------------|\n");
  fclose(fgraduated);
  return FILE_CREATED;
} /* create_graduated_file */


/*
  Name:     update_graduated_file

  Purpose:  to create to the text file of graduated students data

  Params:   IN - graduated_file_name - file name of graduated students list
            IN - student_file_name   - file name of student list
            IN - grades_file_name    - file name of grades list

  Returns:  status of function execution
*/
status update_graduated_file(char *graduated_file_name, char *student_file_name, char *grades_file_name)
{
  FILE *fgraduated;
  FILE *fstudents;
  FILE *fgrades;

  char str1[STR_SIZE];
  char str2[STR_SIZE];
  float average = 0;

  char *token;

  student_t stud_tmp;
  grades_t grades_tmp;

  fgraduated = fopen(graduated_file_name, "a");
  if (fgraduated == NULL)
  {
    return FILE_NOT_EXIST;
  }

  fstudents = fopen(student_file_name, "r");
  if (fstudents == NULL)
  {
    return FILE_NOT_EXIST;
  }

  fgrades = fopen(grades_file_name, "r");
  if (fgrades == NULL)
  {
    return FILE_NOT_EXIST;
  }

  while (fgets(str1, STR_SIZE, fstudents) != NULL)
  {
    token = strtok(str1, "|");
    strcpy(stud_tmp.code, token);
    token = strtok(NULL, "|");
    strcpy(stud_tmp.first_name, token);
    token = strtok(NULL, "|");
    strcpy(stud_tmp.last_name, token);

    rewind(fgrades);
    while (fgets(str2, STR_SIZE, fgrades) != NULL)
    {
      token = strtok(str2, "|");
      strcpy(grades_tmp.code, token);
      token = strtok(NULL, "|");
      grades_tmp.grade1 = atoi(token);
      token = strtok(NULL, "|");
      grades_tmp.grade2 = atoi(token);
      token = strtok(NULL, "|");
      grades_tmp.grade3 = atoi(token);
      
      if (!(strcmp(stud_tmp.code, grades_tmp.code)))
      {
        if ((is_code_in_file(graduated_file_name, stud_tmp.code)) == STUDENT_NOT_EXIST)
        {
          average = (float)(grades_tmp.grade1 + grades_tmp.grade2 + grades_tmp.grade3) / 3;
          if ( average > 5)
          {
            fprintf(fgraduated, 
                    "| %-12s | %-19s | %-20s | %-7.2f |\n", 
                    stud_tmp.code, 
                    stud_tmp.first_name, 
                    stud_tmp.last_name, 
                    average);
          }
        }
      }
    }
  }
  fclose(fgraduated);
  fclose(fstudents);
  fclose(fgrades);
  return STUDENT_ADD_SUCCESSFUL;
} /* update_graduated_file */


/*
  Name:     is_code_in_file

  Purpose:  check if the student code exists in the file

  Params:   IN  - filename - file name of a list
            IN  - code - student code

  Returns:  status of function execution
*/
status is_code_in_file(char *filename, const char *code)
{
  FILE *fptr;
  char str[STR_SIZE];

  fptr = fopen(filename, "r");
  if (fptr == NULL)
  {
    return FILE_NOT_EXIST;
  }
 
  while ((fgets(str, STR_SIZE, fptr)) != NULL)
  {
    if (strstr(str, code) != NULL)
    {
      fclose(fptr);
      return STUDENT_ALREADY_EXIST;
    }
  }
  fclose(fptr);
  return STUDENT_NOT_EXIST;
} /* is_code_in_file */
