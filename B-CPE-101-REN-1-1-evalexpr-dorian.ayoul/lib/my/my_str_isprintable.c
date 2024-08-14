/*
** EPITECH PROJECT, 2020
** my_str_isprintable
** File description:
** Returns 1 if string only has printable chars and 0 if not
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (0 <= str[i] && str[i] <= 31)
            return (0);
    }
    return (1);
}