/*
** EPITECH PROJECT, 2021
** strings_are_identical.c
** File description:
** check if a string is the same as another
*/

int strings_are_identical(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return (0);
        if (str1[i + 1] == '\0' && str2[i + 1] != '\0')
            return (0);
        if (str1[i + 1] != '\0' && str2[i + 1] == '\0')
            return (0);
    }
    return (1);
}