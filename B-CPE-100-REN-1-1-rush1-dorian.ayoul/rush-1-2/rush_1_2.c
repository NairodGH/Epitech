/*
** EPITECH PROJECT, 2020
** rush-1-2
** File description:
** Display square on screen ("/" & "\" & "*")
*/

#include <unistd.h>

void my_putchar(char c);

void my_print_line(int x, int y, int i);

void my_print_first(int x, int y, int i);

void my_print_mid(int x, int y, int i);

void my_print_last(int x, int y, int i);

void rush(int x, int y);

void my_print_line(int x, int y, int i)
{
    if (x == 1) {
        while (i <= y) {
            my_putchar('*');
            my_putchar('\n');
            i++;
        }
    }
    else {
        while (i <= x) {
            my_putchar('*');
            i++;
        }
    }
}

void my_print_first(int x, int y, int i)
{
    int d = 1;

    while (d < x) {
        if (d == 1)
            my_putchar('/');
        else
            my_putchar('*');

        d++;
    }
    my_putchar('\\');
    my_putchar('\n');
}

void my_print_mid(int x, int y, int i)
{
    int d = 1;

    while (d <= x) {
        if (d == 1 || d == x)
            my_putchar('*');
        else
            my_putchar(' ');

        d++;
    }
    my_putchar('\n');
}

void my_print_last(int x, int y, int i)
{
    int d = 1;

    while (d < x) {
        if (d == 1)
            my_putchar('\\');
        else
            my_putchar('*');

        d++;
    }
    my_putchar('/');
    my_putchar('\n');
}

void rush(int x, int y)
{
    int i = 1;

    if (x <= 0 || y <= 0 || x >= 2147483646 || y >= 2147483646) {
        write(1, "Invalid size\n", 13);
        i = y + 1;
    }
    if (x == 1 || y == 1) {
        my_print_line(x, y, i);
        i = y + 1;
    }
    while (i <= y) {
        if (i == 1)
            my_print_first(x, y, i);
        else if (i == y)
            my_print_last(x, y, i);
        else
            my_print_mid(x, y, i);
        i++;
    }
}