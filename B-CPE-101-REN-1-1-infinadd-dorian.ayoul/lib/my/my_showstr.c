/*
** EPITECH PROJECT, 2020
** my_showstr
** File description:
** Prints a string and return 0 (convert non-printable chars hexadecimally)
*/

int my_put_nbr(int nb);

void my_putchar(char c);

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32)
            my_putchar(str[i]);
        if (0 <= str[i] && str[i] <= 31)
            my_putchar('\\');
        if (0 <= str[i] && str[i] <= 15)
            my_putchar('0');
        if (16 <= str[i] && str[i] <= 31)
            my_putchar('1');
        if (0 <= str[i] && str[i] <= 9)
            my_put_nbr(str[i]);
        if ((10 <= str[i]) && (str[i] <= 15))
            my_putchar(str[i] + 87);
        if (16 <= str[i] && str[i] <= 25)
            my_put_nbr(str[i] - 16);
        if (26 <= str[i] && str[i] <= 31)
            my_putchar(str[i] + 71);
    }
    return (0);
}