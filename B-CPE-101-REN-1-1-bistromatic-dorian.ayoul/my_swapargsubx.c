/*
** EPITECH PROJECT, 2020
** swap arg
** File description:
** argv
*/

char **swaparg(char **argv)
{
    int i = 1;
    int c = 3;

    argv[c] = argv[i];
    argv[i] = argv[i + 1];
    argv[i + 1] = argv[c];

    return (argv);
}
