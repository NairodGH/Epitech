/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** Returns 1 if string only has lowercase chars and 0 if not
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!('a' <= str[i] && str[i] <= 'z'))
            return (0);
    }
    return (1);
}