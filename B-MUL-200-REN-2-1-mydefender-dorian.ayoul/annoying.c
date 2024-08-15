/*
** EPITECH PROJECT, 2020
** annoying.c
** File description:
** lib functions
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "include/my_defender.h"

int lib(char *str1, char *str2, int mode)
{
    int nb = 0;

    for (int i = 0; mode == 0 && str1[i] != 0; i++) {
        str2[i] = str1[i];
        if (str1[i + 1] == 0) str2[i + 1] = 0;
    }
    return (nb);
}