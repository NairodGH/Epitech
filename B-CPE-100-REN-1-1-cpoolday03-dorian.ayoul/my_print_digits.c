/*
** EPITECH PROJECT, 2020
** my_print_digits
** File description:
** Display digits in ascending order/single line
*/

#include <unistd.h>

void my_putchar(char c);

int my_print_digits(void);

int my_print_digits(void)
{
    char i = 48;

    while (i <= 57){
        my_putchar(i);
        i++;
    }
    return (0);
}
