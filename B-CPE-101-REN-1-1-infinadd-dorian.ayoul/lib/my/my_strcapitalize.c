/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** Capitalizes the 1rst letter of each word in the string
*/

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[0] >= 'a' && str[0] <= 'z')
            str[0] -= 32;
        if ((str[i] >= 'A') && (str[i] <= 'Z'))
            str[i] += 32;
        if ((str[i - 1] == '+') || (str[i - 1] == '-') || (str[i - 1] == ' ')
            && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] -= 32;
    }
    return (str);
}