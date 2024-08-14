/*
** EPITECH PROJECT, 2020
** my_print_alpha
** File description:
** Display lowercase alphabet in ascending order/single line
*/

#include <unistd.h>

void my_putchar(char c);

int my_print_alpha(void);

int my_print_alpha(void)
{
    char i = 'a';

    while (i <= 'z') {
        my_putchar(i);
        i++;
    }
    return (0);
}
