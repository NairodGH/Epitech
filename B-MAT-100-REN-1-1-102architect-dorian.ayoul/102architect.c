/*
** EPITECH PROJECT, 2020
** 102architect.c
** File description:
** geometrical transformations with matrixes
*/

#include <math.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void check_errors(int argc, char **argv, int i) //check rigor errors
{
    if (argc < 5) printf("Not enough parameters (%d)\n", argc - 1), exit(84);
    for (int j = (argv[1][0] == '-' && argv[1][1] != '\0' ? 1 : 0); argv[1][j] != '\0'; j++)
        if (!('0' <= argv[1][j] && argv[1][j] <= '9')) printf("%s is not a number\n", argv[1]), exit(84);
    for (int j = (argv[2][0] == '-' && argv[2][1] != '\0' ? 1 : 0); argv[2][j] != '\0'; j++)
        if (!('0' <= argv[2][j] && argv[2][j] <= '9')) printf("%s is not a number\n", argv[2]), exit(84);

    if (argv[i][1] == 't' || argv[i][1] == 'z') {
        if (argc < i + 3) printf("Not enough arguments (-t or -z needs 2)\n"), exit(84);
        for (int j = (argv[i + 1][0] == '-' && argv[i + 1][1] != '\0' ? 1 : 0); argv[i + 1][j] != '\0'; j++) 
            if (!('0' <= argv[i + 1][j] && argv[i + 1][j] <= '9')) printf("%s is not a number\n", argv[i + 1]), exit(84);
        for (int j = (argv[i + 2][0] == '-' && argv[i + 2][1] != '\0' ? 1 : 0); argv[i + 2][j] != '\0'; j++)
            if (!('0' <= argv[i + 2][j] && argv[i + 2][j] <= '9')) printf("%s is not a number\n", argv[i + 2]), exit(84);
        if (argc > i + 3) {
            for (int j = (argv[i + 3][0] == '-' && argv[i + 3][1] != '\0' ? 1 : 0); argv[i + 3][j] != '\0'; j++)
                if ('0' <= argv[i + 3][j] && argv[i + 3][j] <= '9') printf("Too much arguments (-t or -z needs 2)\n"), exit(84);
        }
    }
    if (argv[i][1] == 'r' || argv[i][1] == 's') {
        if (argc < i + 2) printf("Not enough arguments (-r or -s needs 1)\n"), exit(84);
        for (int j = (argv[i + 1][0] == '-' && argv[i + 1][1] != '\0' ? 1 : 0); argv[i + 1][j] != '\0'; j++) 
            if (!('0' <= argv[i + 1][j] && argv[i + 1][j] <= '9')) printf("%s is not a number\n", argv[i + 1]), exit(84);
        if (argc > i + 2) {
            for (int j = (argv[i + 2][0] == '-' && argv[i + 2][1] != '\0' ? 1 : 0); argv[i + 2][j] != '\0'; j++)
                if ('0' <= argv[i + 2][j] && argv[i + 2][j] <= '9') printf("Too much arguments (-r or -s needs 1)\n"), exit(84);
        }
    }
}

int main(int argc, char **argv)
{
    check_errors(argc, argv, 0);
    int coords[3] = {atoi(argv[1]),
                     atoi(argv[2]),
                     1};
    float answer[3];
    int m = 0;
    float result[3][3] = {{1, 0, 0},
                          {0, 1, 0},
                          {0, 0, 1}};
    float matrix[argc][3][3]; //create the array of matrixes browsed by m
    matrix[0][0][0] = 0, matrix[0][0][1] = 0, matrix[0][0][2] = 0,
    matrix[0][1][0] = 0, matrix[0][1][1] = 0, matrix[0][1][2] = 0,
    matrix[0][2][0] = 0, matrix[0][2][1] = 0, matrix[0][2][2] = 0;

    for (int i = 3; i != argc; i++) { //transformations matrixes and invalid parameters
        if (argv[i][0] == '-' && argv[i][1] == 't' && argv[i][2] == '\0') {
            check_errors(argc, argv, i);
            printf("Translation along vector (%d, %d)\n", atoi(argv[i + 1]), atoi(argv[i + 2]));
            m++;
            matrix[m][0][0] = 1, matrix[m][0][1] = 0, matrix[m][0][2] = atoi(argv[i + 1]),
            matrix[m][1][0] = 0, matrix[m][1][1] = 1, matrix[m][1][2] = atoi(argv[i + 2]),
            matrix[m][2][0] = 0, matrix[m][2][1] = 0, matrix[m][2][2] = 1;
        }
        else if (argv[i][0] == '-' && argv[i][1] == 'z' && argv[i][2] == '\0') {
            check_errors(argc, argv, i);
            printf("Scaling by factors %d and %d\n", atoi(argv[i + 1]), atoi(argv[i + 2]));
            m++;
            matrix[m][0][0] = atoi(argv[i + 1]), matrix[m][0][1] = 0, matrix[m][0][2] = 0,
            matrix[m][1][0] = 0, matrix[m][1][1] = atoi(argv[i + 2]), matrix[m][1][2] = 0,
            matrix[m][2][0] = 0, matrix[m][2][1] = 0, matrix[m][2][2] = 1;
        }
        else if (argv[i][0] == '-' && argv[i][1] == 'r' && argv[i][2] == '\0') {
            check_errors(argc, argv, i);
            printf("Rotation by a %d degree angle\n", atoi(argv[i + 1]));
            m++;
            matrix[m][0][0] = cos(atoi(argv[i + 1])*(M_PI/180)), matrix[m][0][1] = -sin(atoi(argv[i + 1])*(M_PI/180)), matrix[m][0][2] = 0,
            matrix[m][1][0] = sin(atoi(argv[i + 1])*(M_PI/180)), matrix[m][1][1] = cos(atoi(argv[i + 1])*(M_PI/180)), matrix[m][1][2] = 0,
            matrix[m][2][0] = 0, matrix[m][2][1] = 0, matrix[m][2][2] = 1;
        }
        else if (argv[i][0] == '-' && argv[i][1] == 's' && argv[i][2] == '\0') {
            check_errors(argc, argv, i);
            printf("Reflection over an axis with an inclination angle of %d degrees\n", atoi(argv[i + 1]));
            m++;
            matrix[m][0][0] = cos(2*atoi(argv[i + 1])*(M_PI/180)), matrix[m][0][1] = sin(2*atoi(argv[i + 1])*(M_PI/180)), matrix[m][0][2] = 0,
            matrix[m][1][0] = sin(2*atoi(argv[i + 1])*(M_PI/180)), matrix[m][1][1] = -cos(2*atoi(argv[i + 1])*(M_PI/180)), matrix[m][1][2] = 0,
            matrix[m][2][0] = 0, matrix[m][2][1] = 0, matrix[m][2][2] = 1;
            if (-0.005 < -cos(2*atoi(argv[i + 1])*(M_PI/180)) && -cos(2*atoi(argv[i + 1])*(M_PI/180)) < 0) matrix[m][1][1] = 0.00;
        }
        else {
            for (int j = (argv[i][0] == '-' && argv[i][1] != '\0' ? 1 : 0); argv[i][j] != '\0'; j++)
                if (!('0' <= argv[i][j] && argv[i][j] <= '9')) printf("%s is not a valid parameter\n", argv[i]), exit(84);
        }
    }
    for (; m != 0; m--) { //matrix multiplication
        for (int i = 0; i != 3; i++) {
            for (int j = 0; j != 3; j++) {
                for (int k = 0; k != 3; k++) {
                    matrix[0][i][j] += result[i][k]*matrix[m][k][j];
                }
            }
        }
    }
    for (int i = 0; i != 3; i++) { //result calculation
        for (int j = 0; j != 3; j++) {
            answer[i] += matrix[0][i][j]*coords[j];
        }
    }
    printf("%-8.2f%-8.2f%.2f\n%-8.2f%-8.2f%.2f\n%-8.2f%-8.2f%.2f\n", //displayings
            matrix[0][0][0], matrix[0][0][1], matrix[0][0][2],
            matrix[0][1][0], matrix[0][1][1], matrix[0][1][2],
            matrix[0][2][0], matrix[0][2][1], matrix[0][2][2]);
    printf("(%d.00, %d.00) => (%.2f, %.2f)\n", coords[0], coords[1], answer[0], answer[1]);
    return (0);
}