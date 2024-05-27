/*
  Name:        test_main.c

  Purpose:     File contains tests for functions decribed in student_list.c
  
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <string.h>
#include "../src/student_list.h"

void test_create_stud_file(void **state);
void test_create_grades_file(void **state);
void test_create_graduated_file(void **state);
void test_add_student(void **state);
void test_add_grades(void **state);
void test_update_graduated_list(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_create_stud_file),
    cmocka_unit_test(test_create_grades_file),
    cmocka_unit_test(test_create_graduated_file),
    cmocka_unit_test(test_add_student),
    cmocka_unit_test(test_add_grades),
    cmocka_unit_test(test_update_graduated_list)

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}


/*
  Name:     test_create_stud_file

  Purpose:  Test the function create_student_file()

*/
void test_create_stud_file(void **state)
{
  int result;

  result = create_student_file("tests/students.txt");

  assert_int_equal(result, FILE_CREATED);

} /* test_create_stud_file */


/*
  Name:     test_create_grades_file

  Purpose:  Test the function create_grades_file()

*/
void test_create_grades_file(void **state)
{
  int result;

  result = create_grades_file("tests/grades.txt");

  assert_int_equal(result, FILE_CREATED);
} /* test_create_grades_file */


/*
  Name:     test_create_graduated_file

  Purpose:  Test the function create_graduated_file()

*/
void test_create_graduated_file(void **state)
{
  int result;

  result = create_graduated_file("tests/graduated.txt");

  assert_int_equal(result, FILE_CREATED);
} /* test_create_grades_file */


/*
  Name:     test_add_student

  Purpose:  Test the function add_student

*/
void test_add_student(void **state)
{
  int result;
  student_t stud;
  char fn_students[] = "tests/students.txt";

  strncpy(stud.code, "0001", 5);
  strncpy(stud.first_name, "John", 5);
  strncpy(stud.last_name, "Carmack", 8);
  stud.age = 20;

  result = is_code_in_file(fn_students, stud.code);
  assert_int_equal(result, STUDENT_NOT_EXIST);
  result = add_student(&stud, fn_students);
  assert_int_equal(result, STUDENT_ADD_SUCCESSFUL);
  result = is_code_in_file(fn_students, stud.code);
  assert_int_equal(result, STUDENT_ALREADY_EXIST);

  strcpy(stud.code, "0002");
  strcpy(stud.first_name, "John");
  strcpy(stud.last_name, "Romero");
  stud.age = 25;

  result = is_code_in_file(fn_students, stud.code);
  assert_int_equal(result, STUDENT_NOT_EXIST);
  result = add_student(&stud, fn_students);
  assert_int_equal(result, STUDENT_ADD_SUCCESSFUL);
  result = is_code_in_file(fn_students, stud.code);
  assert_int_equal(result, STUDENT_ALREADY_EXIST);

  strcpy(stud.code, "0003");
  stud.age = -1;
  result = add_student(&stud, fn_students);
  assert_int_equal(result, INVALID_VALUE);
} /* test_add_student */

/*
  Name:     test_add_grades

  Purpose:  Test the function add_grades

*/
void test_add_grades(void **state)
{
  int result;
  grades_t grades;
  char fn_grades[] = "tests/grades.txt";

  strcpy(grades.code, "0001");
  grades.grade1 = 10;
  grades.grade2 = 9;
  grades.grade3 = 8;

  result = is_code_in_file(fn_grades, grades.code);
  assert_int_equal(result, STUDENT_NOT_EXIST);
  result = add_grades(&grades, fn_grades);
  assert_int_equal(result, STUDENT_ADD_SUCCESSFUL);  
  result = is_code_in_file(fn_grades, grades.code);
  assert_int_equal(result, STUDENT_ALREADY_EXIST);

  strcpy(grades.code, "0002");
  grades.grade1 = 5;
  grades.grade2 = 4;
  grades.grade3 = 5;

  result = is_code_in_file(fn_grades, grades.code);
  assert_int_equal(result, STUDENT_NOT_EXIST);
  result = add_grades(&grades, fn_grades);
  assert_int_equal(result, STUDENT_ADD_SUCCESSFUL);
  result = is_code_in_file(fn_grades, grades.code);
  assert_int_equal(result, STUDENT_ALREADY_EXIST);

  strcpy(grades.code, "0003");
  grades.grade1 = -5;
  grades.grade2 = 5;
  grades.grade3 = 5;
  result = add_grades(&grades, fn_grades);
  assert_int_equal(result, INVALID_VALUE);

  grades.grade1 = 5;
  grades.grade2 = -5;
  grades.grade3 = 5;
  result = add_grades(&grades, fn_grades);
  assert_int_equal(result, INVALID_VALUE);

  grades.grade1 = 5;
  grades.grade2 = 5;
  grades.grade3 = -5;
  result = add_grades(&grades, fn_grades);
  assert_int_equal(result, INVALID_VALUE);

} /* test_add_grades */


/*
  Name:     test_update_graduated_list

  Purpose:  Test the function update_graduated_file

*/
void test_update_graduated_list(void **state)
{
  int result;
  char code[] = "0001";
  char fn_graduated[] = "tests/graduated.txt";
  char fn_students[]  = "tests/students.txt";
  char fn_grades[]    = "tests/grades.txt";

  result = is_code_in_file(fn_graduated, code);
  assert_int_equal(result, STUDENT_NOT_EXIST);
  result = update_graduated_file(fn_graduated, fn_students, fn_grades);
  assert_int_equal(result, STUDENT_ADD_SUCCESSFUL);
  result = is_code_in_file(fn_graduated, code);
  assert_int_equal(result, STUDENT_ALREADY_EXIST);
 
  strcpy(code, "0005");
  result = is_code_in_file(fn_graduated, code);
  assert_int_equal(result, STUDENT_NOT_EXIST);
} /* test_update_graduated_list */
