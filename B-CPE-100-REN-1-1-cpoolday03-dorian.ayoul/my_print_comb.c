/*
** EPITECH PROJECT, 2020
** my_print_comb
** File description:
** Display 3-digit numbers with a<b<c in ascending order/single line
*/

#include <unistd.h>

void my_putchar(char c);

void clock(int a, int b, int c);

int my_print_comb(void);

void clock(int a, int b, int c)
{
    while (c <= '9') {
        my_putchar(a);
        my_putchar(b);
        my_putchar(c);
        if ( a != '7' ) {
            my_putchar(',');
            my_putchar(' ');
        }
        c++;
    }
}

int my_print_comb(void)
{
    int a = '0';
    int b = '0';
    int c = '1';

    while (a <= '7') {
        b = a + 1;
        while (b <= '8') {
            c = b + 1;
            clock(a, b, c);
        b++;
        }
    a++;
    }
    return (0);
}
