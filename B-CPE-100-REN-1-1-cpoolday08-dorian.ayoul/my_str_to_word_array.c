/*
** EPITECH PROJECT, 2020
** my_str_word_array
** File description:
** Splits a string into words
*/

#include <stdlib.h>

int my_strlen(char const *str);

void my_putchar(char c);

void my_putstr(char const *str);

int my_count_size(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str [i] >= 'a' && str[i] <= 'z' || str[i] >= 'A'
                && str[i] <= 'Z' || str[i] >= '0' && str[i] <= '9')) {
            count++;
        }
    }
    return (count + 1);
}

char **my_display_array(int size, char const *str, char **rt)
{
    int count = 0;
    int d = 0;
    int i = 0;

    for (i = 0; i != size; i++) {
        while (str [d] >= 'a' && str[d] <= 'z' || str[d] >= 'A'
                && str[d] <= 'Z' || str[d] >= '0' && str[d] <= '9') {
            rt[i][count] = str[d];
            d++;
            count++;
        }
        rt[i][count] = '\0';
        count = 0;
        d++;
    }
    rt[i] = 0;
    return (rt);
}

char **my_str_to_word_array(char const *str)
{
    int size = my_count_size(str);
    int d = 0;
    int i = 0;
    int count = 0;
    char **rt = malloc(sizeof(char *) * (size));

    if (str[0] == '\0') {
        return (NULL);
    }
    for (i = 0; i != size; i++) {
        while (str [d] >= 'a' && str[d] <= 'z' || str[d] >= 'A'
                && str[d] <= 'Z' || str[d] >= '0' && str[d] <= '9') {
            d++;
            count++;
        }
        rt[i] = malloc(sizeof(char) * (count));
        count = 0;
        d++;
    }
    my_display_array(size, str, rt);
}