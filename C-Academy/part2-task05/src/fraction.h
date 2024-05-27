/*
  Name:        fraction.h
                                                                           
  Purpose:     File contains declaration of functions described in fraction.c                        
                                                                           
*/

#ifndef CONVERT_SYMBOLS_H_INCLUDED
#define CONVERT_SYMBOLS_H_INCLUDED

typedef struct
{
    int num;
    int den;
} fraction;

void add_two_fractions(fraction *f1, fraction *f2, fraction *result);
int find_gcd(int num, int den);

#endif // CONVERT_SYMBOLS_H_INCLUDED
