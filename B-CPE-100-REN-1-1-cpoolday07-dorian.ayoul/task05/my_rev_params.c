/*
** EPITECH PROJECT, 2020
** my_rev_params
** File description:
** Displays main function arguments but reversed
*/

void my_putchar2(char c)
{
    write(1, &c, 1);
}

void my_putstr2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar2(str[i]);
        i++;
    }
}

int main (int argc, char **argv)
{
    int i = argc;

    while (0 < i--) {
        my_putstr2(argv[i]);
        my_putchar2('\n');
    }
    return (0);
}