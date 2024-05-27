#include <stdio.h>
#include <stdlib.h>


int DivFunc(int * iPtr);

int main()
{
    char Str1[5] = "Ping";
    char Str2[5] = "Pong";

    for(int i = 1; i <= 100; i++)
    {
        switch(DivFunc(&i))
        {
            case 1 : printf("%d\n", i); break;
            case 2 : printf("%s\n", Str1); break;
            case 3 : printf("%s\n", Str2); break;
            case 4 : printf("%s%s\n", Str1, Str2); break;
        }
    }

    return 0;
}


int DivFunc(int * iPtr)
{
    int n = 1;

    if ((*iPtr % 2 == 0) && (*iPtr % 3 == 0)) { n=4; return n; }
    if (*iPtr % 2 == 0) n=2;
    if (*iPtr % 3 == 0) n=3;

    return n;
}


