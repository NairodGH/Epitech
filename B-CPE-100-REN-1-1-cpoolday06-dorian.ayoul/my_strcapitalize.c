/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** Capitalizes the 1rst letter of each word in the string
*/

char *my_strcapitalize (char *str)
{
    int i = 0;
    int c = 0;

    while (str[i] != '\0') {
        if ((str[0] >= 'a') && (str[0] <= 'z')) {
            str[0] -= 32;
            c = 1;
        }
        if ((str[i - 1] == '+') || (str[i - 1] == '-') || (str[i - 1] == ' ')
                && (str[i] >= 'a') && (str[i] <= 'z') && (c > 1)) {
            str[i] -= 32;
            c = 2;
        }
        if ((str[i] >= 'A') && (str[i] <= 'Z') && (c > 2)) {
            str[i] += 32;
        }
        i++;
    }
    return (str);
}