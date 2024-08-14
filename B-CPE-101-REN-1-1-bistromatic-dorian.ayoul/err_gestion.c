/*
** EPITECH PROJECT, 2020
** Error gestion src file
** File description:
** error handling
*/

#include "include/my.h"
#include "include/bistromatic.h"
#include <stdlib.h>
#include <unistd.h>

void err_print(int type)
{
    if (type == 0)
        my_put_str_err(ERROR_MSG);
    else if (type == 1)
        my_put_str_err(SYNTAX_ERROR_MSG);
    my_putchar_err('\n');
    exit(84);
}

void err_gestion(int ac, char **av)
{
    int i = 0;
    char c;

    if (ac != 4)
        err_print(0);
    else if (my_strlen(av[2]) != 7)
        err_print(1);
    for (i = 0; av[1][i] != '\0'; i++) {
        c = av[1][i];
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
            err_print(1);
        else if (i > 0 && (av[1][i] == av[1][i - 1]))
            err_print(1);
    }
    for (i = 1; av[2][i] != '\0'; i++) {
        if (av[2][i] == av[2][i - 1])
            err_print(1);
    }
}

void my_putchar_err(char c)
{
    write(2, &c, 1);
}

void my_put_str_err(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar_err(str[i]);
    }
}