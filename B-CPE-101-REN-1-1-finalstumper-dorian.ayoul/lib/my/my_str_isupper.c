/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** Returns 1 if string only has uppercase chars and 0 if not
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!('A' <= str[i] && str[i] <= 'Z'))
            return (0);
    }
    return (1);
}