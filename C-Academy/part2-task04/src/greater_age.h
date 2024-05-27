/*
  Name:        greater_age.h
                                                                           
  Purpose:     File contains declaration of functions described in greater_age.c                        
                                                                           
*/

#ifndef GREATER_AGE_H_INCLUDED
#define GREATER_AGE_H_INCLUDED

typedef struct
{
  char* name;
  int age;
} person;

person* whose_age_is_greater(person* first, person* second);

#endif // GREATER_AGE_H_INCLUDED
