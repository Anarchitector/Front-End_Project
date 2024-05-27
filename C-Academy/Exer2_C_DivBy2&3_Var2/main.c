#include <stdio.h>
#include "stdbool.h"

int main()
{
   char Str1[5] = "Ping";
   char Str2[5] = "Pong";
   char Str3[5] = "Pang";
   bool flag = false;

   for(int i = 1; i <= 100; i++)
   {
       flag = false;
       if (i % 2 == 0) {printf("%s", Str1); flag = true; }
       if (i % 3 == 0) {printf("%s", Str2); flag = true; }
       if (i % 5 == 0) {printf("%s", Str3); flag = true; }
       if (!flag) printf("%d",i);
       printf("\n");
   }

    return 0;
}


/*
        if ((i % 2 == 0) && (i % 3 == 0))
        {
            printf("\n%s%s", Str1, Str2);
            if (i % 5 == 0) printf("%s", Str3);
        }
        else
        {
            if (i % 2 == 0)
            {
                printf("\n%s", Str1);
                if (i % 5 == 0) printf("%s", Str3);
            }
            if (i % 3 == 0)
            {
                printf("\n%s", Str2);
                if (i % 5 == 0) printf("%s", Str3);
            }
        }
        if ((i % 2 != 0) && (i % 3 != 0) && (i % 5 != 0)) printf("\n%d", i);
    }
*/
