/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** header
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int get_map_length(char *str);
int get_map_height(char *str);
int my_strlen(char *str);
int my_getnbr(char *str);

#endif
