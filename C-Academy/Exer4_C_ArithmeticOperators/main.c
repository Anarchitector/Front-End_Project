#include <stdio.h>
#include <stdlib.h>

int ChooseTheOperation(char * Op, int * First, int * Second);

int main()
{
    int a = 0, b = 0, c = 0, d = 0;
    int Output = 0;
    char Op[4];

    Op[4] = '\0';
    printf("Variables: ");
    scanf("%d,%d,%d,%d", &a, &b, &c, &d);

    printf("\nOperations:");
    scanf("%s", Op);
    Output = ChooseTheOperation(&Op[0], &a, &b);
    Output = ChooseTheOperation(&Op[1], &Output, &c);
    Output = ChooseTheOperation(&Op[2], &Output, &d);

    printf("\nOutput: %d", Output);

    return 0;
}

int ChooseTheOperation(char * Op, int * First, int * Second)
{
    int Out = 0;

    if(*Op == '+') Out = *First + *Second;
    if(*Op == '-') Out = *First - *Second;

    return Out;
}

/*
    if(Op1[0] == '+') Output = a+b;
    if(Op1[0] == '-') Output = a-b;

    if(Op1[1] == '+') Output = Output+c;
    if(Op1[1] == '-') Output = Output-c;

    if(Op1[2] == '+') Output = Output+d;
    if(Op1[2] == '-') Output = Output-d;
*/


