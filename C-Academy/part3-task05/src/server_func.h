/*
  Name:        server_func.h
                                                                           
  Purpose:     File contains declaration of functions described in convert_symbols.c                        
                                                                           
*/

#ifndef SERVER_FUNC_H_INCLUDED
#define SERVER_FUNC_H_INCLUDED

#define BUFFER_LENGHT  1024
typedef enum
{
  STR_IS_STR,
  STR_IS_NUM
} str_status;

str_status check_str(char* message);
void double_the_number_str(char *buffer);
void run_client();
void run_server();

#endif // SERVER_FUNC_H_INCLUDED
