/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** Concatenates a string with another
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char *src)
{
    int i = my_strlen(dest);
    int j = 0;

    while (src[j] != '\0') {
        dest[i] = src[j];
        i += 1;
        j += 1;
    }
    dest[i] = '\0';
    return (dest);
}