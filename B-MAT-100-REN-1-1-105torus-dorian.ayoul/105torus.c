/*
** EPITECH PROJECT, 2020
** 105torus.c
** File description:
** Mathematics of a donut
*/

#include <math.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int torus(char **av)
{
    double a = 0, fa, m = 0.5, fm, b = 1; //variables declarations with initial values as indicated in the pdf

    for (int i = 1; i < 51; i++, fa = 0, fm = 0) { //main loop runs 50 times max

        for (int j = 6; j != 1; j--) //calculate the ordinates depending on the method
            fa += atoi(av[j]) *
            (j != 2 ? pow((av[1][0] == '2' ? m : a), j - 2) : 1);
        for (int j = 6; j != (av[1][0] == '2' ? 2 : 1); j--)
            fm += (av[1][0] == '2' ? j - 2 : 1) *
            atoi(av[j]) *
            (j != (av[1][0] == '2' ? 3 : 2) ? pow((av[1][0] == '3' ? b : m), j - (av[1][0] == '2' ? 3 : 2)) : 1);

        if (av[1][0] == '1' && (fa < 0 && fm > 0 || fa > 0 && fm < 0)) b = m; //some in-between calculations depending on the method
        else if (av[1][0] == '1') a = m;
        if (av[1][0] == '2' && fm == 0) return(84);
        else if (av[1][0] == '2') a = m - (fa / fm);
        if (av[1][0] == '3' && fm - fa == 0) return(84);
        else if (av[1][0] == '3') m = b - (fm * (b - a) / (fm - fa)), a = b, b = m;

        if (av[1][0] == '3' && round(a * pow(10, atoi(av[7]))) == round(b * pow(10, atoi(av[7])))) break;
        if (av[1][0] == '1' && i <= atoi(av[7])) printf("x = %.*f\n", i, m); //prints and stop condition depending on the method
        else if (i == 1) printf("x = %.*f\n", (m * 10 == round(m * 10) ? 1 : atoi(av[7])), m);
        else printf("x = %.*f\n", atoi(av[7]), m);
        if (round(a * pow(10, atoi(av[7]))) == round((av[1][0] == '2' ? m : b) * pow(10, atoi(av[7])))) break;

        if (av[1][0] == '1') m = (a + b) / 2; //quick last calculations depending on the method
        if (av[1][0] == '2') m = a;
    }
}

int main(int ac, char **av)
{
    if (ac != 8) { //error handling and prints
        printf("[ERROR] There should be 7 arguments (currently %d).\n", ac - 1);
        return (84);
    }
    for (int i = 1; i != 8; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] == '-' && j == 0) j++;
            if (av[i][j] < 48 || av[i][j] > 57) {
                printf("[ERROR] The argument %d (%s) is not a valid integer.\n", i - 1, av[i]);
                return (84);
            }
        }
    }
    if (atoi(av[7]) < 0) {
        printf("[ERROR] The precision (%s) is not positive.\n", av[7]);
        return (84);
    }
    if (atoi(av[1]) < 1 || atoi(av[1]) > 3) {
        printf("[ERROR] The method option (%s) is not 1, 2 or 3.\n", av[1]);
        return (84);
    }
    if (atoi(av[4]) == 0 && atoi(av[5]) == 0 && atoi(av[6]) == 0) {
        if (atoi(av[3]) == 0) {
            printf("[ERROR] No solution.\n");
            return (84);
        }
        else {
            printf("x = 0.5\n");
            return (0);
        }
    }
    if (atoi(av[1]) == 3 && atoi(av[6]) > 10) {
        printf("[ERROR] No convergence for option 3.\n");
        return (84);
    }
    if (torus(av) == 84) {
        printf("[ERROR] Division by 0.\n");
        return (84);
    }
    return (0);
}