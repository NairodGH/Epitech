/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

int my_getnbr(char const *str)
{
    int negative = 0;
    long long nbr = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '-' && !(str[i] >= '0' && str[i] <= '9'))
            negative = 0;
        if (str[i] == '-')
            negative++;
        if (str[i] >= '0' && str[i] <= '9') {
            nbr += str[i] - 48;
            nbr *= 10;
        }
        if ((str[i] >= '0' && str[i] <= '9')
            && (str[i + 1] < '0' || str[i + 1] > '9')) {
            nbr /= 10;
            if (negative % 2 != 0)
                nbr *= -1;
            return (nbr);
        }
    }
}