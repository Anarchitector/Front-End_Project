#ifndef CAR_LIST_PROCESSING_H_INCLUDED
#define CAR_LIST_PROCESSING_H_INCLUDED

#define MAX_CARS  100

typedef enum {
              SUCCESS = 0,
              FULL_CAR_ARRAY,
              INVALID_SEATS_PARAM,
              INVALID_POWER_PARAM,
              INVALID_YEAR_PARAM,
              NO_CARS_AT_INPUT_LIST,
              NO_CARS_AT_OUTPUT_LIST
             } car_add_result;

typedef struct
{
  int seats;   // between 2 and 8
  int power;   // greater than 0
  char brand[20]; // string with max 20 characters
  char color[20]; // string with max 20 characters
  int year;    // Number not greater than current year
} car;


int display_main_menu();
int add_cars(car *cars, const int *cars_cnt, car user_input);
void add_new_car(car *cars, int *cars_cnt, car user_input);
void order_by_power(car *input_array, int car_num, car *output_array);
int filter_by_year(car *input_array, 
                   int input_car_num, 
                   car *output_array, 
                   int *output_car_num, 
                   int year);


#endif // CAR_LIST_PROCESSING_H_INCLUDED
