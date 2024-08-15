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
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>
#include <errno.h>

//libc
int strings_are_identical(char *str1, char *str2);
int str_is_positive_int(char *str);
size_t string_length(char *str);
void display_int(int nb);
void display_char(char c);
void my_putchar(char c);
int get_int(char *str);
size_t get_height(char *str);
int get_unsigned(char *str);
size_t copy_string(char *source, char *destination);
char **copy_2d(char **src, char **dest);

#endif