/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** Sort int array in ascending order
*/

void my_sort_int_array(int *tab, int size)
{
    int temp = 0;

    for (int i = 0; i != size; i++) {
        if (i > 0 && tab[i - 1] > tab[i]) {
            temp = tab[i];
            tab[i] = tab [i - 1];
            tab [i - 1] = temp;
            i = 0;
        }
    }
}