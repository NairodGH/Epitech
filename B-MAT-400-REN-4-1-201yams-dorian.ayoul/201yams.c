/*
** EPITECH PROJECT, 2022
** 201yams.c
** File description:
** 201yams
*/

#include <stdio.h>
#include <stdlib.h>

int help()
{
    printf("USAGE\n\t./201yams d1 d2 d3 d4 d5 c\n\nDESCRIPTION\n");
    printf("\td1\tvalue of the first die (0 if not thrown)\n");
    printf("\td2\tvalue of the second die (0 if not thrown)\n");
    printf("\td3\tvalue of the third die (0 if not thrown)\n");
    printf("\td4\tvalue of the fourth die (0 if not thrown)\n");
    printf("\td5\tvalue of the fifth die (0 if not thrown)\n");
    printf("\tc\texpected combination\n");
    return 84;
}

int main(int ac, char **av)
{
    if (ac != 7)
        exit(help());
    for (size_t i = 1; i < 6; i++)
        if (av[i][0] < '0' || av[i][0] > '6' || av[i][1] != '\0')
            exit(help());
    int **rolls = malloc(sizeof(int *) * 7776);
    for (size_t i = 0; i < 7776; i++)
        rolls[i] = malloc(sizeof(int) * 5);
    // if (av[6][0] == 'p' && av[6][1] == 'a' && av[6][2] == 'i' && av[6][3] == 'r' && av[6][4] == '_' && av[6][5] > '0' && av[6][5] < '7' && av[6][6] == '\0')
    // else if (av[6][0] == 't' && av[6][1] == 'h' && av[6][2] == 'r' && av[6][3] == 'e' && av[6][4] == 'e' && av[6][5] == '_' && av[6][6] > '0' && av[6][6] < '7' && av[6][7] == '\0')
    // else if (av[6][0] == 'f' && av[6][1] == 'o' && av[6][2] == 'u' && av[6][3] == 'r' && av[6][4] == '_' && av[6][5] > '0' && av[6][5] < '7' && av[6][6] == '\0')
    // else if (av[6][0] == 'f' && av[6][1] == 'u' && av[6][2] == 'l' && av[6][3] == 'l' && av[6][4] == '_' && av[6][5] > '0' && av[6][5] < '7' && av[6][6] == '_' && av[6][7] > '0' && av[6][8] < '7' && av[6][9] == '\0')
    // else if (av[6][0] == 's' && av[6][1] == 't' && av[6][2] == 'r' && av[6][3] == 'a' && av[6][4] == 'i' && av[6][5] == 'g' && av[6][6] == 'h' && av[6][7] == 't' && av[6][8] == '_' && av[6][9] > '4' && av[6][9] < '7' && av[6][10] == '\0')
    // else if (av[6][0] == 'y' && av[6][1] == 'a' && av[6][2] == 'm' && av[6][3] == 's' && av[6][4] == '_' && av[6][5] > '0' && av[6][5] < '7' && av[6][6] == '\0')
    // else
    //     exit(help());
    return 0;
}
