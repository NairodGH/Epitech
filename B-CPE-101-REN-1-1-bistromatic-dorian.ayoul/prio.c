/*
** EPITECH PROJECT, 2020
** Parsing for NPI
** File description:
** NPI PARS
*/

#include "my.h"
#include "ops.h"

int is_op(char str)
{
    if (str == '+' || str == '-' || str == '*'
        || str == '/' || str == '%')
        return 1;
    else
        return 0;
}

int is_prio(char str)
{
    if (str == '+' || str == '-' || str == '(')
        return 0;
    if (!(is_op(str)))
        exit(84);
    else
        return 1;
}

int comp_prio(char *stack, char str, int *stackcount)
{
    if (*stackcount == 0)
        return 0;
    else if (is_prio(stack[*stackcount - 1]) < is_prio(str))
        return 0;
    else if (is_prio(stack[*stackcount - 1]) > is_prio(str))
        return 1;
    return 0;
}

void push_stack(char **dest, char *stack, int *stackcount, int *d)
{
    while (*stackcount >= 0) {
        if (stack[*stackcount] == '(')
            return;
        dest[*d][0] = stack[*stackcount];
        stack[*stackcount] = 0;
        (*stackcount)--;
        (*d)++;
    }
    (*stackcount)++;
}

void push_par(char **dest, char *stack, int *stackcount, int *d)
{
    while (stack[*stackcount] != '(') {
        stack[*stackcount] = 0;
        (*stackcount)--;
        if (stack[*stackcount] == '(')
            return;
        (*d)++;
        dest[*d][0] = stack[*stackcount];
    }
    stack[*stackcount] = 0;
}