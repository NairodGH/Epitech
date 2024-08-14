/*
** EPITECH PROJECT, 2020
** splitting funcs
** File description:
** des
*/

#include "my.h"
#include "ops.h"

void set_end(char **dest, int *d, int *count)
{
    dest[*d][*count] = '\0';
    (*d)++;
    (*count) = 0;
}

void set_count(char **dest, char str, int d, int *count)
{
    dest[d][*count] = str;
    (*count)++;
}

void set_stack(char *stack, char *str, int i, int *stackcount)
{
    if ((str[i + 1] >= '0' && str[i + 1] <= '9')
        && (str[i - 1] < '0' || str[i - 1] > '9'))
        return;
    stack[*stackcount] = str[i];
    (*stackcount)++;
}

void parenthesis(char str, char *stack, int *stackcount)
{
    if (str == '(') {
        stack[*stackcount] = str;
        (*stackcount)++;
    }
    else
        exit(84);
}

int checkpar(char *str, int i)
{
    if ((str[i + 1] >= '0' && str[i + 1] <= '9')
        && (str[i - 1] < '0' || str[i - 1] > '9'))
        return (1);
    else
        return (0);
}
