/*
** EPITECH PROJECT, 2020
** do-op
** File description:
** Computes an operation
*/

#include <stddef.h>
#include "my.h"

int separ_op(char const *argv[], int a, int b)
{
    if (argv[2][0] == '*') {
        my_put_nbr(a * b);
        return (0);
    }
    if (argv[2][0] == '/') {
        if (b == 0) {
            write(2, "Stop: division by zero\n", 23);
            return (69420);
        }
        my_put_nbr(a / b);
        return (0);
    }
    if (argv[2][0] == '%') {
        if (b == 0) {
            write(2, "Stop: modulo by zero\n", 21);
            return (69420);
        }
        my_put_nbr(a % b);
        return (0);
    }
}

int do_op(char const *argv[], int i)
{
    int a = my_getnbr(argv[1]);
    int b = my_getnbr(argv[3]);

    if (!((argv[1][0] >= '0' && argv[1][0] <= '9') || argv[1][0] == '-'))
        a = 0;
    if (!((argv[3][0] >= '0' && argv[3][0] <= '9') || argv[3][0] == '-'))
        b = 0;
    if (argv[2][0] == '+') {
        my_put_nbr(a + b);
        return (0);
    }
    if (argv[2][0] == '-') {
        my_put_nbr(a - b);
        return (0);
    }
    if (!(argv[2][0] == '+' || argv[2][0] == '-' || argv[2][0] == '*'
        || argv[2][0] == '/' || argv[2][0] == '%'))
        return (360666);
    i = separ_op(argv, a, b);
    return (i);
}

int main(int argc, char const *argv[])
{
    int i = 0;

    if (argc != 4) {
        return (84);
    }
    i = do_op(argv, i);
    if (i == 69420)
        return (84);
    if (i == 360666)
        my_put_nbr(0);
        return (84);
    return (0);
}