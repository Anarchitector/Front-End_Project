#include <stdio.h>
#include <stdlib.h>
#include "minutes_to_years.h"

int main()
{
    long minutes;

    printf("Enter the number of minutes :");
    scanf("%ld", &minutes);

    printf("%ld minutes is \n", minutes);
    printf("Years: %d\n", convert_minutes_to_years(minutes));
    printf("Days: %d\n", convert_minutes_to_remaining_days(minutes));

    printf("\n");
    return 0;
}
