/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** Concatenates a string with another until the n char
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char *src, int n)
{
    int i = my_strlen(dest);
    int j = 0;

    while (j < n && src[j] != '\0') {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return (dest);
}