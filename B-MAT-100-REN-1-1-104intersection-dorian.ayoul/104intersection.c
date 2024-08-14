/*
** EPITECH PROJECT, 2020
** 104intersection.c
** File description:
** Third dimension and quadratic equations
*/

#include <math.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int intersection(char **av)
{
    double a, b, c, d, angle = atof(av[8]) * M_PI / 180; //variables

    for (int i = 2; i != (av[1][0] == '2' ? 4 : 5); i++) { //loop algorithm to calculate a, b, c
        a += pow(atof(av[i + 3]), 2)*(av[1][0] == '3' && i == 4 ? -pow(tan(angle), 2) : 1);
        b += 2*atof(av[i])*atof(av[i + 3])*(av[1][0] == '3' && i == 4 ? -pow(tan(angle), 2) : 1);
        c += pow(atof(av[i]), 2)*(av[1][0] == '3' && i == 4 ? -pow(tan(angle), 2) : 1);
    }
    (av[1][0] == '1' || av[1][0] == '2') && (c -= pow(atof(av[8]), 2));

    if ((d = pow(b, 2) - 4*a*c) < 0) printf("No intersection point.\n"); //prints
    else if (d == 0 || pow(a, 2) < 0.0000001) {
        if (av[1][0] == '2' && atoi(av[5]) == 0 && atoi(av[6]) == 0)
            printf("There is an infinite number of intersection points.\n");
        else if (av[1][0] == '3' && pow(a, 2) < 0.0000001 && pow(b, 2) < 0.0000001 && pow(c, 2) < 0.0000001)
            printf("There is an infinite number of intersection points.\n");
        else if (pow(a, 2) < 0.0000001) {
            printf("1 intersection point:\n");
            printf("(%.3f,", atof(av[2]) + -c/b * atof(av[5]));
            printf(" %.3f,", atof(av[3]) + -c/b * atof(av[6]));
            printf(" %.3f)\n", atof(av[4]) + -c/b * atof(av[7]));
        }
        else {
            printf("1 intersection point:\n");
            printf("(%.3f,", atof(av[2]) + -b/(2*a) * atof(av[5]));
            printf(" %.3f,", atof(av[3]) + -b/(2*a) * atof(av[6]));
            printf(" %.3f)\n", atof(av[4]) + -b/(2*a) * atof(av[7]));
        }
    }
    else {
        printf("2 intersection points:\n");
        printf("(%.3f,", atof(av[2]) + (-b + sqrt(d)) / (2*a) * atof(av[5]));
        printf(" %.3f,", atof(av[3]) + (-b + sqrt(d)) / (2*a) * atof(av[6]));
        printf(" %.3f)\n", atof(av[4]) + (-b + sqrt(d)) / (2*a) * atof(av[7]));
        printf("(%.3f,", atof(av[2]) + (-b - sqrt(d)) / (2*a) * atof(av[5]));
        printf(" %.3f,", atof(av[3]) + (-b - sqrt(d)) / (2*a) * atof(av[6]));
        printf(" %.3f)\n", atof(av[4]) + (-b - sqrt(d)) / (2*a) * atof(av[7]));
    }
}

int main(int ac, char **av)
{
    if (ac != 9) { //error handling and prints
        printf("[ERROR] There should be 9 arguments (currently %d).\n", ac);
        return (84);
    }
    for (int i = 0; av[8][i] != '\0'; i++) {
        if (av[8][i] < 48 || av[8][i] > 57) {
            printf("[ERROR] The parameter (%s) is not a valid positive integer.\n", av[8]);
            return (84);
        }
    }
    if (av[1][0] == '3' && av[1][1] == '\0' && atof(av[8]) > 90) {
        printf("[ERROR] The cone angle (%s) must be bellow 90°.\n", av[8]);
        return (84);
    }
    if (av[1][0] == '1' && av[1][1] == '\0') printf("Sphere of radius %s\n", av[8]);
    else if (av[1][0] == '2' && av[1][1] == '\0') printf("Cylinder of radius %s\n", av[8]);
    else if (av[1][0] == '3' && av[1][1] == '\0') printf("Cone with a %s degree angle\n", av[8]);
    else {
        printf("[ERROR] The surface option (%s) is not 1, 2 or 3.\n", av[1]);
        return (84);
    }
    for (int i = 2; i != 8; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] == '-' && j == 0) j++;
            if (av[i][j] < 48 || av[i][j] > 57) {
                printf("[ERROR] The coordinate %d (%s) is not a valid integer.\n", i - 1, av[i]);
                return (84);
            }
        }
    }
    if (atof(av[5]) == 0 && atof(av[6]) == 0 && atof(av[7]) == 0) {
        printf("[ERROR] The direction vector should not be null.\n");
        return (84);
    }
    printf("Line passing through the point (%s, %s, %s) and parallel to the vector (%s, %s, %s)\n", av[2], av[3], av[4], av[5], av[6], av[7]);
    intersection(av);
    return (0);
}