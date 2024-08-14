/*
** EPITECH PROJECT, 2020
** char to NPI
** File description:
** des
*/

#include "my.h"
#include "ops.h"

static int countops(char *tab)
{
    int d = 0;

    for (int i = 0; tab[i] != '\0'; i++) {
        if (tab[i] == '+' || tab[i] == '-' || tab[i] == '*'
            || tab[i] == '/' || tab[i] == '%')
            d++;
    }
    return (d);
}

static void mallocmachine(char **dest, char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        dest[i] = malloc(sizeof(char) * my_strlen(str));
    }
}

static void endfunc(char **dest, char *stack, int *stackcount, int *d)
{
    (*d)++;
    (*stackcount)--;
    push_stack(dest, stack, stackcount, d);
    dest[*d] = 0;
}

static char **tradpol(char *str, char *stack, char **dest, int do_push)
{
    int d = 0;
    int count = 0;
    int stackc = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            set_count(dest, str[i], d, &count);
        else if (str[i] == '(')
            parenthesis(str[i], stack, &stackc);
        else if (is_op(str[i])) {
            (checkpar(str, i)) ? (dest[d][count] = str[i], count++)
        : set_end(dest, &d, &count);
            do_push = comp_prio(stack, str[i], &stackc);
            (do_push == 1) ? (stackc--, push_stack(dest, stack, &stackc, &d),
        set_stack(stack, str, i, &stackc)) : set_stack(stack, str, i, &stackc);
        }
        else if (str[i] == ')')
            push_par(dest, stack, &stackc, &d);
    }
    endfunc(dest, stack, &stackc, &d);
}

char **trad(char *str)
{
    int do_push = 0;
    char *stack = malloc(sizeof(char) * (countops(str) + 1));
    char **dest = malloc(sizeof(char) * ((my_strlen(str) + 1000)));

    mallocmachine(dest, str);
    tradpol(str, stack, dest, do_push);
    return (dest);
}
