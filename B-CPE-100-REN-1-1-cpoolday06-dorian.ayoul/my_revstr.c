/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** Reverses a string
*/

char *my_revstr(char *str)
{
    int   a = 0;
    int   b = 0;
    char  temp;

    while (str[b] != 0)
        b++;
    b -= 1;
    while (a < b) {
        temp = str[a];
        str[a] = str[b];
        str[b] = temp;
        a++;
        b--;
    }
    return (str);
}