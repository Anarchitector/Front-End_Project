#include <stdio.h>
#include <stdlib.h>

#include "car_list_processing.h"

int main()
{
  car user_input;
  int cars_cnt = 0;
  int filter_cnt = 0;
  int year = 0;
  car cars[MAX_CARS];
  car sort_by_power[MAX_CARS];
  car filter_year[MAX_CARS];
  char any_key;

  do
  {
    switch(display_main_menu())
    {
      case 1 :
      {
        add_new_car(&cars[cars_cnt], &cars_cnt, user_input);
        break;
      }
      case 2 :
      {
        int i;
        order_by_power(cars, cars_cnt, sort_by_power);
        printf("\n| %-7s | %-7s | %-15s | %-7s | %-7s |", 
              "Seats", 
              "Power", 
              "Brand", 
              "Color", 
              "Year");
        printf("\n--------------------------------------------------");
        for (i = 0; i < cars_cnt; i++)
        {
          printf("\n| %-7d | %-7d | %-15s | %-7s | %-7d |", 
          sort_by_power[i].seats, 
          sort_by_power[i].power, 
          sort_by_power[i].brand, 
          sort_by_power[i].color, 
          sort_by_power[i].year);
        }
        printf("\nPress any key and press Enter to return to main menu : ");
        scanf(" %c", &any_key);
        break;
      }
      case 3 :
      {
        int i;
        if (cars_cnt <= 0)
        {
            printf("\nNo cars added to list\n");
            printf("\nPress any key and press Enter to return to main menu : ");
            scanf(" %c", &any_key);
        }
        else
        {
          printf("\nEnter the year to filter: ");
          scanf("%d", &year);
          switch(filter_by_year(cars, cars_cnt, filter_year, &filter_cnt, year))
          {
            case SUCCESS :
            {
              printf("\nCar list filtered by year : %d", year);
              printf("\n| %-7s | %-7s | %-15s | %-7s | %-7s |", 
                    "Seats", 
                    "Power", 
                    "Brand", 
                    "Color", 
                    "Year");
              printf("\n--------------------------------------------------");
              for (i = 0; i < filter_cnt; i++)
              {
                printf("\n| %-7d | %-7d | %-15s | %-7s | %-7d |", 
                filter_year[i].seats, 
                filter_year[i].power, 
                filter_year[i].brand, 
                filter_year[i].color, 
                filter_year[i].year);
              }
              printf("\nPress any key and press Enter to return to main menu : ");
              scanf(" %c", &any_key);
              break;
            }
            case NO_CARS_AT_INPUT_LIST :
            {
              printf("\nNo cars added to list\n");
              printf("\nPress any key and press Enter to return to main menu : ");
              scanf(" %c", &any_key);
              break;
            }
            case NO_CARS_AT_OUTPUT_LIST :
            {
              printf("No cars of %d year at a list", year);
              printf("\nPress any key and press Enter to return to main menu : ");
              scanf(" %c", &any_key);
            }
          }
        }
        break;
      }
      case 4 :
      {
        exit(0);
        break;
      }
    }
  } while (1);

  return 0;
} /* main */
