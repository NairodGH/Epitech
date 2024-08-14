/*
** EPITECH PROJECT, 2020
** rush-1-1
** File description:
** Display square on screen ("o" & "-" & " | ")
*/

#include <unistd.h>

void my_putchar(char c);

void my_print_first(int x, int y, int i);

void my_print_mid(int x, int y, int i);

void rush(int x, int y);

void my_print_first(int x, int y, int i)
{
    int d = 1;

    while (d <= x) {
        if (d == 1 || d == x)
            my_putchar('o');
        else
            my_putchar('-');
        d++;
    }
    my_putchar('\n');
}

void my_print_mid(int x, int y, int i)
{
    int d = 1;

    while (d <= x) {
        if (d == 1 || d == x)
            my_putchar('|');
        else
            my_putchar(' ');
        d++;
    }
    my_putchar('\n');
}

void rush(int x, int y)
{
    int i = 1;

    if (x <= 0 || y <= 0 || x >= 2147483646 || y >= 2147483646) {
        write(1, "Invalid size\n", 13);
        i = y + 1;
    }
    while (i <= y) {
        if (i == 1 || i == y)
            my_print_first(x, y, i);
        else
            my_print_mid(x, y, i);
        i++;
    }
}