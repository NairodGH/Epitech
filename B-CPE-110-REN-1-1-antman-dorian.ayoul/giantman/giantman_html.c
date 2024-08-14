/*
** EPITECH PROJECT, 2020
** antman.c
** File description:
** bop
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "antman.h"

int my_case2(char *str, int i)
{
    switch (str[i]) {
        case -1 : write(1, "return", 6); break;
        case -2 : write(1, "amazon", 6); break;
        case -3 : write(1, "google", 6); break;
        case -4 : write(1, "window", 6); break;
        case -5 : write(1, "images", 6); break;
        case -6 : write(1, "prototype", 9); break;
        case -7 : write(1, "null", 4); break;
        case -8 : write(1, "ikipedia", 8); break;
        case 7 : write(1, "script", 6); break;
        case 5 : write(1, "function", 8); break;
        case 25 : write(1, "div", 3); break;
        case 26 : write(1, "https://", 8); break;
        case 27 : write(1, "span", 4); break;
        case 29 : write(1, ".com", 4); break;
        case 30 : write(1, "article", 7); break;
        case 31 : write(1, "img", 3); break;
        default : write(1, &str[i], 1);
    }
    return (0);
}

int my_case(char *str, int i)
{
    switch (str[i]) {
        case -9 : write(1, "crossorigin", 11); break;
        case -10 : write(1, "github", 6); break;
        case -11 : write(1, "GitHub", 6); break;
        case 6 : write(1, "style", 5); break;
        case 12 : write(1, "title", 5); break;
        case 13 : write(1, "head", 4); break;
        case 14 : write(1, "width", 5); break;
        case 15 : write(1, "height", 6); break;
        case 16 : write(1, "body", 4); break;
        case 17 : write(1, "meta", 4); break;
        case 18 : write(1, "link", 4); break;
        case 19 : write(1, "property", 8); break;
        case 20 : write(1, "content", 7); break;
        case 21 : write(1, "href", 4); break;
        case 22 : write(1, "rel", 3); break;
        case 23 : write(1, "name", 4); break;
        case 24 : write(1, "class", 5); break;
        default : my_case2(str, i);
    }
}

int check_space(char *str, int *i)
{
    int a = 0;
    int nb = 0;

    if (str[*i + 2] == 28 && (str[*i + 1] >= '0' && str[*i + 1] <= '9')
        && str[*i] >= '0' && str[*i] <= '9') {
        nb = str[*i] - 48;
        nb = nb * 10;
        nb = nb + str[*i + 1] - 48;
        while (a != nb - 1)
            write(1, " ", 1), a++;
        *i = *i + 3;
    }
    else if (str[*i + 1] == 28 && (str[*i] >= '0' && str[*i] <= '9')) {
        nb = str[*i] - 48;
        while (a != nb - 1)
            write(1, " ", 1), a++;
        *i = *i + 2;
    }
    return (0);
}

int check_backl(char *str, int *i)
{
    int a = 0;
    int nb = 0;

    if (str[*i + 2] == 4 && (str[*i + 1] >= '0' && str[*i + 1] <= '9')
        && str[*i] >= '0' && str[*i] <= '9') {
        nb = str[*i] - 48;
        nb = nb * 10;
        nb = nb + str[*i + 1] - 48;
        while (a != nb - 1)
            write(1, "\n", 1), a++;
        *i = *i + 3;
    }
    else if (str[*i + 1] == 4 && (str[*i] >= '0' && str[*i] <= '9')) {
        nb = str[*i] - 48;
        while (a != nb - 1)
            write(1, "\n", 1), a++;
        *i = *i + 2;
    }
    return (0);
}

int giant_html(char *str)
{
    int i = 0;
    char save;
    while (str[i] != '\0') {
        check_space(str, &i), check_backl(str, &i);
        switch (str[i]) {
            case -12 : write(1, "=\"", 2); break;
            case 1 : write(1, "\">", 2); break;
            case 11 : write(1, "</", 2); break;
            case -13 : write(1, "media", 5); break;
            case -14 : write(1, "dns-prefetch", 12); break;
            case 2 : write(1, "edge", 4); break;
            case 3 : write(1, "item", 4); break;
            case 8 : write(1, "<li", 3); break;
            case 127 : write(1, "input", 5); break;
            default : my_case(str, i);
        }
        i++;
    }
    return (0);
}