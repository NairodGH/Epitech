/*
** EPITECH PROJECT, 2020
** my_evil_str
** File description:
** Swap each string's chars 2 by 2
*/

int m_strlen(char const *str);

char *my_evil_str(char *str);

int m_strlen(char const *str)
{
    int i = 0;

    while ( str[i] != '\0') {
        i++;
    }
    i--;
    return (i);
}

char *my_evil_str(char *str)
{
    int f = 0;
    int last = m_strlen(str);
    char c;

    while (f < last) {
        c = str[f];
        str[f] = str[last];
        str[last] = c;
        f++;
        last--;
    }
    return (str);
}
