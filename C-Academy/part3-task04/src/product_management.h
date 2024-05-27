#ifndef PRODUCT_MANAGEMENT_H_INCLUDED
#define PRODUCT_MANAGEMENT_H_INCLUDED

#define STR_SIZE 100

typedef struct
{
  int   code;
  char  name[50];
  float price;
  int   quantity;
} product_t;

typedef enum
{
  FILE_CREATED,
  FILE_NOT_CREATED,
  FILE_NOT_EXIST,
  FILE_ALREADY_EXIST,
  PRODUCT_ADD_SUCCESSFUL,
  PRODUCT_NOT_EXIST,
  PRODUCT_ALREADY_EXIST,
  INVALID_VALUE
} status;

status check_file(char *filename);
char display_main_menu();
void help_menu();
status create_product_file(char *filename);
status add_product(char *filename, product_t *product);
status print_all_products(char *filename);

int save(char * filename, product_t * st, int n);
int load(char * filename);


#endif // PRODUCT_MANAGEMENT_H_INCLUDED
