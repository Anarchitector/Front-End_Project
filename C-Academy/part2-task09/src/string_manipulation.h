/*
  Name:        string_manipulation.h
                                                                           
  Purpose:     File contains declaration of functions described in string_manipulation.c                        
                                                                           
*/
#ifndef STRING_MANIPULATION_H_INCLUDED
#define STRING_MANIPULATION_H_INCLUDED


int s_len(const char* str);
char* find_char(const char letter, char* str, int str_len);
void trim_vowel(char* input, char* output);
int is_palindrome(const char* input);


#endif // STRING_MANIPULATION_H_INCLUDED
