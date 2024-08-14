/*
** EPITECH PROJECT, 2020
** my_print_revalpha
** File description:
** Display lowercase alphabet in descending order/single line
*/

#include <unistd.h>

void my_putchar(char c);

int my_print_revalpha(void);

int my_print_revalpha(void)
{
    char i = 'z';

    while (i >= 'a') {
        my_putchar(i);
        i--;
    }
    return (0);
}
