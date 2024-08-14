/*
** EPITECH PROJECT, 2020
** finalstumper
** File description:
** read finalstumper
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "rush3.h"

int my_display(char *buff, int z);

int my_check_error(char *buff);

int my_count(char *buff);

int my_count_large(char *buff, int z);

int my_checkB_else(char *buff);

int my_checkB_last(char *buff);

int my_checkB(char *buff)
{
    int i = 0;
    int z = 0;

    while (buff[i] != '\n')
        i++;
    if (buff[i - 1] == 'B') {
        my_putstr("[rush1-3]");
        my_display(buff, z);
        my_putstr(" || ");
        my_putstr("[rush1-4]");
        my_display(buff, z);
        my_putstr(" || ");
        my_putstr("[rush1-5]");
        my_display(buff, z);
        my_putchar('\n');
        return (0);
    }
    else
        my_checkB_else(buff);
    return (0);
}

int my_checkB_else(char *buff)
{
    int i = 0;
    int z = 0;

    while (buff[i] != '\n')
        i++;
    i--;
    if (buff[i] == 'A') {
        my_putstr("[rush1-3]");
        my_display(buff, z);
        my_putchar('\n');
        return (0);
    }
    else
        my_checkB_last(buff);
    return (0);
}

int my_checkB_last(char *buff)
{
    int i = 0;
    int z = 0;

    while (buff[i] != '\0')
        i++;
    i = i - 2;
    while (buff[i] == 'C') {
        my_putstr("[rush1-4]");
        my_display(buff, z);
        my_putchar('\n');
        return (0);
    }
    my_putstr("[rush1-5]");
    my_display(buff, z);
    my_putchar('\n');
    return (0);
}

int rush3(char *buff)
{
    int z = 0;

    if (my_check_error(buff) == 84)
        return (84);
    if (buff[1] == 'o') {
        my_putstr("[rush1-1]");
        my_display(buff, z);
        my_putchar('\n');
        return (0);
    }
    if (buff[1] == '*' || buff[1] == '/') {
        my_putstr("[rush1-2]");
        my_display(buff, z);
        my_putchar('\n');
        return (0);
    }
    else
        my_checkB(buff);
    return (0);
}

int main()
{
    char buff[BUFF_SIZE + 1];
    int offset = 1;
    int len;
    int i = 0;

    while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    i = rush3(buff);
    if (i == 84) {
        write(2, "none\n", 6);
        return (84);
    }
    return (0);
}
