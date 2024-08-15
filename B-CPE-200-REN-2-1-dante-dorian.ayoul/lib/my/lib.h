/*
** EPITECH PROJECT, 2020
** lib.h
** File description:
** Header file for all the lib functions
*/

#ifndef LIB_H
#define LIB_H

#include <math.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

//libc
int strings_are_identical(char *str1, char *str2);
int str_is_positive_int(char *str);
int string_length(char *str);
void display_int(int nb);
void display_char(char c);
void my_putchar(char c);
int get_int(char *str);
size_t get_height(char *str);

#endif