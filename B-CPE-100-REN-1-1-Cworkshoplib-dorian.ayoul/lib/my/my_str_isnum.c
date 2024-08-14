/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** Returns 1 if string only has digits and 0 if not
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!('0' <= str[i] && str[i] <= '9'))
            return (0);
    }
    return (1);
}