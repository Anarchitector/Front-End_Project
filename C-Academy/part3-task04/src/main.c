#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "product_management.h"


int main()
{
  char product_filename[] = "product.dat";

  product_t product;

 if (check_file(product_filename) == FILE_NOT_EXIST)
  {
    create_product_file(product_filename);
  }

  do
  {
    switch(toupper(display_main_menu()))
    {
      case 'H' :
      {
        help_menu();
        break;
      }
      case 'A' :
      {

/*        printf("Enter the product code: ");
        scanf("%d", &product.code);
        printf("Enter the product name: ");
        scanf("%s", product.name);
        do
        {
          printf("Enter the product price: ");
          scanf("%f", &product.price);
        } while (product.price < 0);
        do
        {
          printf("Enter the product quantity: ");
          scanf("%d", &product.quantity);
        } while (product.quantity < 0);
*/

        switch(add_product(product_filename, &product))
//         switch(save(product_filename, &product, 1))
        {
          case FILE_NOT_EXIST :
          {
            perror("Error occured while opening file product.dat");
            break;
          }
          case PRODUCT_ADD_SUCCESSFUL :
          {
            printf("\nThe product was added successfully to the list\n");
            break;
          }
        }
        break;
      }
      case 'W' :
      {
        switch(print_all_products(product_filename))
      //  switch(load(product_filename));
        {
          case FILE_NOT_EXIST :
          {
            perror("Error occured while opening file product.dat");
            break;
          }
          case FILE_CREATED :
          {

            break;
          }
        }
        break;
      }
      case 'B' :
      {
        break;
      }
      case 'E' :
      {
        break;
      }
      case 'X' :
      {
        exit(0);
        break;
      }

    }
  } while (1);

  return 0;
}
