/*
  Name:       main.c

  Purpose:    String manipulation using pointer arithmetics
  
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "string_manipulation.h"

int main()
{
  char* str = "abcdcba";
  char* str_without_vowels = (char*)malloc(strlen(str)*sizeof(char));
  char letter = 'b';
  int str_len = 0;
  
  str_len = s_len(str);
  printf("Length of the string is %d symbols", str_len);

  printf("\nAdress of char %c - %p", letter, find_char(letter, str, str_len));

  trim_vowel(str, str_without_vowels);
  printf("\nString without vowels: ");
  printf("%s", str_without_vowels);

  is_palindrome(str) ? printf("String is a palindrome") : printf("String is not a palindrome");
  
  free(str_without_vowels);

  return 0;
}
