/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** Funtion swapping content of 2 integers
*/

void my_swap(int *a, int *b);

void my_swap(int *a, int *b)
{
    int i;

    i = *a;
    *a = *b;
    *b = i;
}
