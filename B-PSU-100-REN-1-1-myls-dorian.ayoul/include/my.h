/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** Header file containing all prototypes of libmy.a functions
*/

#include <sys/sysmacros.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#ifndef MY_H
#define MY_H

typedef struct data_struct {
    struct passwd *upw;
    struct group *gpw;
    DIR *dir;
    struct stat st;
    struct dirent *sd;
} data_struct;

int listing_form(char **a, char **f, int i, int total);
int normal_form(char **a, char **f, int i);
void normal_print(char **f, int i, char mode);
int args_parser(int ac, char **av, char **a);
int permissions(data_struct d, char *f, int k);
int get_stats(data_struct d, char **f, int i, int total);
int getdate(int d[2][2], char **f, int i, char mode);
void getmonth(int d[2][2], char **f, int j);
void time_sorter(char **f, int i);
void swapstr(char **str1, char **str2);
void my_putchar(char c);
char *putstr(char *str, int nb, char mode);
int my_len(char *str, int nb);
int put_in_str(char *dest, int k, char *srcstr, int srcnbr);

#endif