/*
** EPITECH PROJECT, 2020
** concat_params.c
** File description:
** Turns command-line given argument into a single string
*/

#include <stdlib.h>
#include <stdio.h>

void my_putchar(char c);

int my_putstr(char const *str);

int my_strlen(char const *str);

char *test(int argc, char **argv, char *params)
{
    int i = 0;
    int d = 0;
    int count = 0;

    while (i < argc) {
        while (argv[i][d] != '\0') {
            params[count] = argv[i][d];
            d++;
            count++;
        }
        if (i < argc - 1) {
            params[count] = '\n';
            count++;
        }
        i++;
        d = 0;
    }
    return (params);
}

char *concat_params(int argc, char **argv)
{
    int i = 0;
    int size = 0;
    char *params;

    while (i < argc) {
        size += my_strlen(argv[i]);
        i++;
    }
    params = malloc(sizeof(char) * (size + i));
    params = test(argc, argv, params);
    return (params);
}