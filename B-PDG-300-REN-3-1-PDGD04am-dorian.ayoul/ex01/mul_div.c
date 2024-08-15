/*
** EPITECH PROJECT, 2022
** mul_div.c
** File description:
** performs multiplication and division at the same time !
*/

void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = a * b;
    if (b == 0)
        *div = 42;
    else
        *div = a / b;
}

void mul_div_short(int *a, int *b)
{
    int c;

    c = (*a) * (*b);
    if (*b == 0)
        *b = 42;
    else
        *b = (*a) / (*b);
    *a = c;
}