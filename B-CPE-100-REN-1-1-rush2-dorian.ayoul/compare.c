/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** Guesses the language of a string
*/

#include "my.h"
#include <stdio.h>

void low_case(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
        my_strlowcase(argv[i]);
}

void print_result(int engl, int fr, int ger, int spa)
{
    int who_will_be_print = 0;

    if ((engl > fr) && (engl > ger) && (engl > spa))
        my_putstr("=> English\n");
    if ((fr > engl) && (fr > ger) && (fr > spa))
        my_putstr("=> French\n");
    if ((ger > fr) && (ger > engl) && (ger > spa))
        my_putstr("=> German\n");
    if ((spa > fr) && (spa > ger) && (spa > engl))
        my_putstr("=> Spanish\n");
}

void compare(float *language, float *percent, int argc, char **argv)
{
    int letter = 0;
    int nbr_alpha = 0;
    int nbr_match_engl = 0;
    int nbr_match_fr = 0;
    int nbr_match_ger = 0;
    int nbr_match_spa = 0;

    low_case(argc, argv);
    for (int i = 0; argv[1] != NULL && argv[1][i] != '\0'; i++) {
        if (argv[1][i] == ' ' || argv[1][i] == '.' ||
        argv[1][i] == ',' || argv[1][i] == 39)
            i++;
        letter = argv[1][i] - 97;
        for (int h = 0; h < 3; h++) {
            if (language[h * 26 + letter] < language[(h + 1) * 26 + letter])
                nbr_alpha = h + 1;
        }
        if (nbr_alpha == 0)
            nbr_match_engl++;
        if (nbr_alpha == 1)
            nbr_match_fr++;
        if (nbr_alpha == 2)
            nbr_match_ger++;
        if (nbr_alpha == 3)
            nbr_match_spa++;
        nbr_alpha = 0;
    }
    print_result(nbr_match_engl, nbr_match_fr, nbr_match_ger, nbr_match_spa);
}
