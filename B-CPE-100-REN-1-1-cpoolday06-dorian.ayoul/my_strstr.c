/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** Searches for a string inside another
*/

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int a = 0;
    int c = 0;

    while (to_find[a] == '\0')
        return (str);
    while (str[i] != '\0') {
        c = i;
        while (to_find[a] == str[i]) {
            a++;
            i++;
        }
        if (to_find[a] == '\0')
            return (&str[c]);
        i++;
    }
    return (0);
}