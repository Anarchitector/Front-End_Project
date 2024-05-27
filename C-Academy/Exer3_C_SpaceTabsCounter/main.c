#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>

int SpaceCnt = 0;
int TabsCnt = 0;
int NumCnt = 0;
int NumArray[10] = {0};
int c = 0;

char Str[200];

int main()
{
    printf("Enter the string:\n");
    gets(Str);

    for(int i = 0; Str[i] != '\0'; i++)
    {
        if(Str[i] == ' ') SpaceCnt++;
        if(Str[i] == '\t') TabsCnt++;
        if(isdigit(Str[i])) NumCnt++;
        if(isdigit(Str[i]))
        {
            c = (int)Str[i]-48;
            NumArray[c]++;
        }
    }

    printf("%d\n", SpaceCnt);
    printf("%d\n", TabsCnt);
    printf("%d\n", NumCnt);
    printf("\n");

    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", NumArray[i]);
    }

    return 0;
}
