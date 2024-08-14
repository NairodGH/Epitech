/*
** EPITECH PROJECT, 2020
** my_print_comb2
** File description:
** Display all combinations of 2 2-digit numbers
*/

#include <unistd.h>

void my_putchar(char c);

int put(int a, int b);

int my_print_comb2(void);

int put(int a, int b)
{
    while (b <= 99) {
        if (a == 0 && b == 0 || a == b) {
            b++;
        }
        my_putchar(48 + (a / 10));
        my_putchar(48 + (a % 10));
        my_putchar(' ');
        my_putchar(48 + (b / 10));
        my_putchar(48 + (b % 10));
        if (a == 98 && b == 99) {
            return (0);
        }
        my_putchar(',');
        my_putchar(' ');
        b++;
    }
}

int my_print_comb2(void)
{
    int a = 0;
    int b = 0;

    while (a <= 98) {
        b = a;
        put(a, b);
        a++;
    }
    return (0);
}
