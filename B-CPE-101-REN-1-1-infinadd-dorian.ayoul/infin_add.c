/*
** EPITECH PROJECT, 2020
** infin_add
** File description:
** Performs infinite addition
*/

#include <stdlib.h>
#include "include/my.h"

int I = 0;
int J = 0;
int K = 0;
int NEG = 0;
int RET = 0;

int prepare_nbr(char *argv[], int NEG)
{
    my_revstr(argv[1]);
    my_revstr(argv[2]);
    if (argv[1][my_strlen(argv[1]) - 1] == '-' &&
    argv[2][my_strlen(argv[2]) - 1] == '-') {
        argv[1][my_strlen(argv[1]) - 1] = '\0';
        argv[2][my_strlen(argv[2]) - 1] = '\0';
        NEG = 1;
    }
    return (NEG);
}

void show_nbr(char *nbr, int NEG)
{
    my_revstr(nbr);
    if (NEG == 1)
        my_putchar('-');
    my_putstr(nbr);
    free(nbr);
}

void infin_add(char *argv[], char *nbr)
{
    NEG = prepare_nbr(argv, NEG);
    for (; argv[1][I] != '\0' && argv[2][J] != '\0'; I++, J++, K++) {
        if ((((argv[1][I] + argv[2][J]) - 48) + RET) > '9') {
            nbr[K] = ((((argv[1][I] + argv[2][J]) - 96) + RET) % 10) + 48;
            RET = 1;
        }
        else {
            nbr[K] = ((argv[1][I] + argv[2][J]) - 48) + RET;
            RET = 0;
        }
    }
    for (; argv[1][I] == '\0' && argv[2][J] != '\0'; J++, K++) {
        nbr[K] = ((argv[2][J] - 48) + RET) + 48;
        RET = 0;
    }
    for (; argv[1][I] != '\0' && argv[2][J] == '\0'; I++, K++) {
        nbr[K] = ((argv[1][I] - 48) + RET) + 48;
        RET = 0;
    }
    show_nbr(nbr, NEG);
}

int main(int argc, char *argv[])
{
    char *nbr = malloc(sizeof(char) * 1000);

    infin_add(argv, nbr);
    return (0);
}