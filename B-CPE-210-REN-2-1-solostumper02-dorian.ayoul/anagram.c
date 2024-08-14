/*
** EPITECH PROJECT, 2021
** anagram.c
** File description:
** find if two strings are anagrams
*/

#include <unistd.h>
#include <stdio.h>

int my_strlen(char *str);

int check(int n[255], int i, char **av)
{
    int ret = 0;

    for (int j = 0, k = n[av[1][i]]; av[2][j] != 0; j++) {
        if (av[2][j] == av[1][i]
        || (64 < av[1][i] && av[1][i] < 91 && av[2][j] - 32 == av[1][i])
        || (96 < av[1][i] && av[1][i] < 123 && av[2][j] + 32 == av[1][i])) {
            k == 0 ? ret = 1 : k--;
        }
    }
    return (ret);
}

int main(int ac, char **av)
{
    int n[255];

    for (int i = 0; i != 255; i++) n[i] = 0;
    if (ac != 3) {
        write(2, "Error: not enough arguments.\n", 29);
        return (84);
    }
    if (my_strlen(av[1]) != my_strlen(av[2])) {
        write(1, "no anagrams.\n", 13);
        return (0);
    }
    for (int i = 0; av[1][i] != 0; i++) {
        if (!check(n, i, av)) {
            write(1, "no anagrams.\n", 13);
            return (0);
        }
        if (64 < av[1][i] && av[1][i] < 91) n[av[1][i]]++, n[av[1][i] + 32]++;
        if (96 < av[1][i] && av[1][i] < 123) n[av[1][i]]++, n[av[1][i] - 32]++;
    }
    write(1, "anagram!\n", 9);
    return (0);
}
