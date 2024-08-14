/*
** EPITECH PROJECT, 2020
** rush_1_3
** File description:
** Display square on screen ("A" & "B" & "C")
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
            my_putchar('B');
            my_putchar('\n');
            i++;
        }
    }
    else {
        while (i <= x) {
            my_putchar('B');
            i++;
        }
    }
}

void my_print_first(int x, int y, int i)
{
    int d = 1;

    while (d < x) {
        if (d == 1)
            my_putchar('A');
        else
            my_putchar('B');

        d++;
    }
    my_putchar('A');
    my_putchar('\n');
}

void my_print_mid(int x, int y, int i)
{
    int d = 1;

    while (d <= x) {
        if (d == 1 || d == x)
            my_putchar('B');
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
            my_putchar('C');
        else
            my_putchar('B');
        d++;
    }
    my_putchar('C');
    my_putchar('\n');
}

void rush(int x, int y)
{
    int i = 1;

    if (x <= 0 || y <= 0 || x >= 2147483646 || y >= 2147483646) {
        write(1, "Invalid size\n", 13);
        i = y + 1;
    }
    else if (x == 1 || y == 1) {
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