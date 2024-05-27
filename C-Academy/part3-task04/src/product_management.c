/*
  Name:      product_management.c

  Purpose:   to manage the information about product
             in a store
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "product_management.h"


/*
  Name:     check_file

  Purpose:  to check at start up if file exist

  Returns:  status exist file or not
*/
status check_file(char *filename)
{
  if (access(filename, F_OK) != -1)
  {
    return FILE_ALREADY_EXIST;
  }
  else
  {
    return FILE_NOT_EXIST;
  }
} /* check_file */


/*
  Name:     display_main_menu

  Purpose:  to display a list of actions

  Returns:  input value by user. If user input is incorrect then nothing happened.
*/
char display_main_menu()
{
  char user_input = 0;

    printf("\n********************************* MAIN MENU *********************************");
    printf("\nh - Information about the program options");
    printf("\na - add a product");
    printf("\nw - print all products from product.dat");
    printf("\nb - read details about one product based on product name");
    printf("\ne - print the most expensive product");
    printf("\nx - close the program\n");
  do
  {
    printf("\n> ");
    scanf(" %c", &user_input);
  } while (!((user_input != 'H') ||
           (user_input != 'A') ||
           (user_input != 'W') ||
           (user_input != 'B') ||
           (user_input != 'E') ||
           (user_input != 'X') ));

  return user_input;
} /* display_main_menu */


/*
  Name:     help_menu

  Purpose:  to display a help menu

  Returns:  Nothing
*/
void help_menu()
{
  printf("\n*********************************** HELP MENU ***********************************");
  printf("\nPress 'h' read the information about the program options");
  printf("\nPress 'a' to add a product in a product list. Follow the program requests.");
  printf("\nPress 'w' to print all products from product.dat");
  printf("\nPress 'b' to read details about one product. Follow the program requests.");
  printf("\nPress 'e' to print the most expensive product");
  printf("\nPress 'x' to close the program\n");
} /* help menu */


status create_product_file(char *filename)
{
  int i;
  product_t product = {0,"",0.0,0};
  FILE *fptr;

  fptr = fopen(filename, "w");
  if (fptr == NULL)
  {
    return FILE_NOT_CREATED;
  }

  for (i = 1; i <= 50; i++)
  {
    fwrite(&product, sizeof(product_t),1,fptr);
  }

  fclose(fptr);
  return FILE_CREATED;
} /* help_menu */


/*
  Name:     help_menu

  Purpose:  to display a help menu

  Params:   filename - name of the product file list
            product  - structure of product parameters

  Returns:  status of function execution
*/
status add_product(char *filename, product_t *product)
{
  FILE *fptr;

  if (product->price < 0)
  {
    return INVALID_VALUE;
  }

  if (product->quantity < 0)
  {
    return INVALID_VALUE;
  }

  fptr = fopen(filename, "ab");
  if (fptr == NULL)
  {
    return FILE_NOT_EXIST;
  }

  printf("Enter code: ");
  scanf("%d", &product->code);
  printf("Enter product: ");
  scanf("%s", product->name);
  printf("Enter price: ");
  scanf("%f", &product->price);
  printf("Enter quantity: ");
  scanf("%d", &product->quantity);

/*  while (product->code != 0)
  {
    printf("Enter info :\n");
    scanf("%s%f%d", product->name, &product->price, &product->quantity);
*/

  fseek(fptr, sizeof(product_t), SEEK_SET);
  fwrite(&product, sizeof(product_t) + 1, 1, fptr);

/*  printf("Enter code: ");
  scanf("%d", &product->code);

  }
*/
  fclose(fptr);
  return PRODUCT_ADD_SUCCESSFUL;
}






status print_all_products(char *filename)
{
  FILE *fptr;

  product_t read_f;

  fptr = fopen(filename, "rb");
  if (fptr == NULL)
  {
    return FILE_NOT_EXIST;
  }

  while (!feof(fptr))
  {
    fread(&read_f, sizeof(product_t) + 1, 1, fptr);
    if (read_f.code != 0)
    {
      printf("%d %s %.2f %d\n",
             read_f.code,
             read_f.name,
             read_f.price,
             read_f.quantity);
    }

  }

  fclose(fptr);
  return 0;

}


// ������ � ���� ������� ��������
int save(char * filename,  product_t * st, int n)
{
    FILE * fp;
    char *c;
    int i;
    int m = sizeof(int);

    // ����� ������������ ������
    int size = n * sizeof(product_t);

    if ((fp = fopen(filename, "r+")) == NULL)
    {
      return FILE_NOT_EXIST;
    }


     // �������� ������ ��� ���������� ������
    int *pti = (int *)malloc(m);


    // ��������� ���������� ��������
    c = (char *)pti;
    while (m>0)
    {
        i = getc(fp);
        if (i == EOF) break;
        *c = i;
        c++;
        m--;
    }
    //�������� ����� ���������
    n = *pti;
    n++;

    fseek(fp, 0, SEEK_SET);


    // ���������� ���������� ��������
    c = (char *)&n;
    for (int i = 0; i<sizeof(int); i++)
    {
        putc(*c++, fp);
    }

    // ����������� ���������� � ���� ��� ���������
    c = (char *)st;
    for (int i = 0; i < size; i++)
    {
        putc(*c, fp);
        c++;
    }
    fclose(fp);
    return PRODUCT_ADD_SUCCESSFUL;
}

// �������� �� ����� ������� ��������
int load(char * filename)
{
    FILE * fp;
    char *c;
    int m = sizeof(int);
    int n, i;

    // �������� ������ ��� ���������� ������
    int *pti = (int *)malloc(m);

    if ((fp = fopen(filename, "r")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    // ��������� ���������� ��������
    c = (char *)pti;
    while (m>0)
    {
        i = getc(fp);
        if (i == EOF) break;
        *c = i;
        c++;
        m--;
    }
    //�������� ����� ���������
    n = *pti;

    // �������� ������ ��� ���������� ������� ��������
    product_t * ptr = (product_t *) malloc(n * sizeof(product_t));
    c = (char *)ptr;
    // ����� ������ ��������� ����������� �� �����
    while ((i= getc(fp))!=EOF)
    {
        *c = i;
        c++;
    }
    // ������� ����������� ��������� � ����� �� �������
    printf("\n%d people in the file stored\n\n", n);

    for (int k = 0; k<n; k++)
    {
        printf("%d %s %.2f %d \n",
               (ptr + k)->code,
               (ptr + k)->name,
               (ptr + k)->price,
               (ptr + k)->quantity);
    }

    free(pti);
    free(ptr);
    fclose(fp);
    return 0;
}


