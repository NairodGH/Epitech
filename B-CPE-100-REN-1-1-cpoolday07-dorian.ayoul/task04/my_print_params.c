/*
** EPITECH PROJECT, 2020
** my_print_params
** File description:
** Displays main function arguments
*/

void my_putchar1(char c)
{
    write(1, &c, 1);
}

void my_putstr1(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar1(str[i]);
        i++;
    }
}

int main (int argc, char **argv)
{
    int i = 0;

    while (i < argc) {
        my_putstr1(argv[i]);
        my_putchar1('\n');
        i++;
    }
    return (0);
}