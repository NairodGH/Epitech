/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** Compares 2 strings up the to the n char
*/

int my_strncmp(char const *s1 , char const *s2 , int n)
{
    int i = 0;

    while (i <= n && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    if ((s1[i] == '\0') && (s2[i] == '\0') || i == n)
        return (0);
    return (s1[i] - s2[i]);
}