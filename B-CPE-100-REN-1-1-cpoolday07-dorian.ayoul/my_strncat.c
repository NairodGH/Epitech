/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** Concatenates a string with another until the n char
*/

int my_strlen2(char const *str)
{
    int j = 0;

    while ( str[j] != '\0') {
        j++;
    }
    return (j);
}

char *my_strncat(char *dest, char *src, int n)
{
    int i = my_strlen2(dest);
    int j = -1;

    while ((++j < n) && (src[j] != '\0')) {
        dest[i + j] = src[j];
    }
    dest[i + j] = '\0';
    return (dest);
}