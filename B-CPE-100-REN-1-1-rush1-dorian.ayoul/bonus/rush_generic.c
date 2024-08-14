/*
** EPITECH PROJECT, 2020
** rush_generic
** File description:
** A bunch of functions to display each type of squares possible
*/

#include<unistd.h>

void my_putchar(char c);

void rush(int x, int y, int type);

void my_print_first(int x, int y, int i, int type, char a, char b, char c);

void my_print_mid(int x, int y, int i, char b, char c);

void my_print_last(int x, int y, int i, int type, char a, char b, char c);

void my_print_line(int x, int y, int i, char b);

char setchar(char *a, char *b, char *c, int type);

char setchar(char *a, char *b, char *c, int type)
{
    if (type == 1) {
        *a = 'o';
        *b = '-';
        *c = '|';
    }
    else if (type == 2) {
        *a = '/';
        *b = '*';
        *c = '\\';
    }
    else if (type >= 3 && type <= 5) {
        *a = 'A';
        *b = 'B';
        *c = 'C';
    }
}

void my_print_line(int x, int y, int i, char b)
{
    if (x == 1) {
        while (i <= y) {
            my_putchar(b);
            my_putchar('\n');
            i++;
        }
    }
    else {
        while (i <= x) {
            my_putchar(b);
            i++;
        }
    }
}

void my_print_last(int x, int y, int i, int type, char a, char b, char c)
{
    int d = 1;

    if (type == 1)
        c = a;
    else if (type == 4) {
        while (d < x) {
            if (d == 1)
                my_putchar(a);
            else
                my_putchar(b);

            d++;
        }
        my_putchar(c);
        my_putchar('\n');
        d = x;
    }
    else if (type == 3) {
        while (d < x) {
            if (d == 1)
                my_putchar(a);
            else
                my_putchar(b);

            d++;
        }
        my_putchar(c);
        my_putchar('\n');
        d = x;
    }
    else {
        while (d < x) {
            if (d == 1)
                my_putchar(c);
            else
                my_putchar(b);

            d++;
        }
    }

    while (d < x) {
        if (d == 1)
            my_putchar(a);
        else
            my_putchar(b);

        d++;
        }

    if (type < 3 || type == 5) {
    my_putchar(a);
    my_putchar('\n');
    }
}

void my_print_mid(int x, int y, int i, char b, char c)
{
    int d = 1;

    if (b == '-')
        b = c;
        
    while (d <= x) {
        if (d == 1 || d == x)
            my_putchar(b);
        else
            my_putchar(' ');

        d++;
    }
    my_putchar('\n');
}

void my_print_first(int x, int y, int i, int type, char a, char b, char c)
{
    int d = 1;

    if (type == 4) {
        while (d < x) {
            if (d == 1)
                my_putchar(a);
            else
                my_putchar(b);

            d++;
        }
    }
    else if (type == 3) {
        while (d < x) {
            if (d == 1)
                my_putchar(a);
            else
                my_putchar(b);

            d++;
        }
    }
    

    while (d < x) {
        if (d == 1)
            my_putchar(a);
        else
            my_putchar(b);

        d++;
    }
    if (type >= 4) {
        my_putchar(c);
        my_putchar('\n');
    }
    else if (type == 1) {
        my_putchar(a);
        my_putchar('\n');
    }
    
}


void my_putchar(char c)
{
    write(1, &c, 1);
}

void rush(int x, int y, int type)
{
    int i = 1;
    char a;
    char b;
    char c;
    
    if (type > 5 || type <= 0) {
        write(1, "Invalid type\n", 13);
        i = y + 1;
    }

    setchar(&a,&b,&c,type);
    
    if (x <= 0 || y <= 0) {
        write(1, "Invalid size\n", 13);
        i = y + 1;
    }
    else if (x == 1 || y == 1) {
        my_print_line(x,y,i,b);
        i = y + 1;
    }

    while (i <= y) {
        if (i == 1)
            my_print_first(x,y,i,type,a,b,c);
        else if (i == y)
            my_print_last(x,y,i,type,a,b,c);
        else
            my_print_mid(x,y,i,b,c);
        i++;
    }
}

int main()
{
    rush(15,15,1);
    return (0);
}
