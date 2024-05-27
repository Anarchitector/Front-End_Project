/*
  Name:        student_list.h

  Purpose:     File contains declaration of functions described in student_list.c

*/

#ifndef STUDENT_LIST_H_INCLUDED
#define STUDENT_LIST_H_INCLUDED

#define CODE_SIZE 20
#define STR_SIZE 1000

typedef struct
{
  char code[CODE_SIZE];
  char first_name[40];
  char last_name[40];
  int  age;
} student_t;

typedef struct
{
  char code[CODE_SIZE];
  int  grade1;
  int  grade2;
  int  grade3;
} grades_t;

typedef struct
{
  char code[CODE_SIZE];
  char first_name[40];
  char last_name[40];
  int grade1;
  int grade2;
  int grade3;
} graduated_t;

typedef enum
{
  FILE_CREATED,
  FILE_NOT_CREATED,
  FILE_NOT_EXIST,
  FILE_ALREADY_EXIST,
  STUDENT_ADD_SUCCESSFUL,
  STUDENT_NOT_EXIST,
  STUDENT_ALREADY_EXIST,
  INVALID_VALUE
} status;

char display_main_menu();
void help_menu();
status check_file(char *filename);
status create_student_file(char *student_file_name);
status create_grades_file(char *grades_file_name);
status create_graduated_file(char *graduated_file_name);
status add_student(student_t *user_input, char *student_file_name);
status add_grades(grades_t *user_input, char *grades_file_name);
status update_graduated_file(char *graduated_file_name, char *student_file_name, char *grades_file_name);
status is_code_in_file(char* filename, const char *code);
void collect_student_info(char *str1, char *str2, graduated_t *tmp);

#endif // STUDENT_LIST_H_INCLUDED
