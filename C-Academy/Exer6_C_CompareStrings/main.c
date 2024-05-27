#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include <string.h>

#define Num 200

char String1[Num], String2[Num];
bool flag = false;
int LenString1 = 0;
int LenString2 = 0;
int x = 0;
int i = 0;


int main()
{
    puts("Enter the first string: ");
    gets(String1);

    puts("Enter the second string: ");
    gets(String2);

    LenString1 = strlen(String1);
    LenString2 = strlen(String2);

    for(x = 0; x < LenString1; x++)
    {
        for(i = 0; i < LenString2; i++)
        {
            if(String1[x+i] == String2[i]) flag = true;
            else { flag = false; break; }
        }
        if(i==LenString2) break;
    }

    if(flag) printf("\nOk");
    else printf("\nNot Ok");

    return 0;
}
