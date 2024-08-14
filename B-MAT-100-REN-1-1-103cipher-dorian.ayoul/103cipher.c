/*
** EPITECH PROJECT, 2020
** 103cipher.c
** File description:
** Mathematical Message Masking Multiplying Matrices
*/

#include <math.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void encrypt(char **argv)
{
    int k = ceil(sqrt(strlen(argv[2]))); //setup the variables/allocations needed
    int j = k;
    int i = ceil(strlen(argv[1]) / k) + 1;
    int **key_matrix = malloc(sizeof(int *) * k);
    for (int a = 0; a != k; a++) key_matrix[a] = malloc(sizeof(int) * j);
    int **message_matrix = malloc(sizeof(int *) * i);
    for (int a = 0; a != i; a++) message_matrix[a] = malloc(sizeof(int) * k);
    int **result_matrix = malloc(sizeof(int *) * i);
    for (int a = 0; a != i; a++) result_matrix[a] = malloc(sizeof(int) * k);

    for (int a = 0; a != k; a++) { //fill the key_matrix and message_matrix with the corresponding ASCII values
        for (int b = 0; b != j; b++) {
            key_matrix[a][b] = argv[2][b + j * a];
            if (b + j * a >= strlen(argv[2])) key_matrix[a][b] = 0;
        }
    }
    for (int a = 0; a != i; a++) {
        for (int b = 0; b != k; b++) {
            message_matrix[a][b] = argv[1][b + k * a];
            if (b + k * a >= strlen(argv[1])) message_matrix[a][b] = 0;
        }
    }

    for (int a = 0; a != i; a++) { //multiply those matrices
        for (int b = 0; b != j; b++) {
            result_matrix[a][b] = 0;
            for (int c = 0; c != k; c++)
                result_matrix[a][b] += message_matrix[a][c] * key_matrix[c][b];
        }
    }

    printf("Key matrix:\n");  //prints
    for (int a = 0; a != k; a++) {
        for (int b = 0; b != j; b++) {
            if (key_matrix[a][b] != 0)
                printf((b < j - 1 ? "%d\t" : "%d"), key_matrix[a][b]);
            else
                printf((b < j - 1 ? "%d\t" : "%d"), key_matrix[a][b]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Encrypted message:\n");
    for (int a = 0; a != i; a++) {
        for (int b = 0; b != k; b++) {
            printf("%d", result_matrix[a][b]);
            if ((a + 1 == i && b + 1 == k) || (b + 1 != k && result_matrix[a][b + 1] == 0) || (b == k - 1 && a + 1 != i && result_matrix[a + 1][0] == 0)) {
                printf("\n");
                exit(0);
            }
            else
                printf(" ");
        }
    }
}

void decrypt(char **argv)
{
    int k = ceil(sqrt(strlen(argv[2]))); //setup the variables/allocations needed
    int j = k;
    int i = 0;
    for (int a = 0; argv[1][a] != '\0'; a++) (argv[1][a] == ' ') && (i++);
    i = ceil(--i / k) + 1;
    int det;
    int c = 0;
    double **key_matrix = malloc(sizeof(double *) * k);
    for (int a = 0; a != k; a++) key_matrix[a] = malloc(sizeof(double) * j);
    int **message_matrix = malloc(sizeof(int *) * i);
    for (int a = 0; a != i; a++) message_matrix[a] = malloc(sizeof(int) * k);
    int **comatrix = malloc(sizeof(int *) * k);
    for (int a = 0; a != k; a++) comatrix[a] = malloc(sizeof(int) * j);
    int **decrypted_matrix = malloc(sizeof(int *) * i);
    for (int a = 0; a != i; a++) decrypted_matrix[a] = malloc(sizeof(int) * k);

    for (int a = 0; a != k; a++) { //fill the key_matrix and message_matrix with the corresponding ASCII values
        for (int b = 0; b != j; b++) {
            key_matrix[a][b] = argv[2][b + j * a];
            if (b + j * a >= strlen(argv[2])) key_matrix[a][b] = 0;
        }
    }
    for (int a = 0; a != i; a++) {
        for (int b = 0; b != k; b++) {
            for (; argv[1][c] != ' ' && argv[1][c] != '\0'; c++)
                message_matrix[a][b] *= 10, message_matrix[a][b] += argv[1][c] - 48;
            if (argv[1][c] == ' ') c++;
        }
    }

    if (k == 1) //get the determinant
        det = key_matrix[0][0];
    if (k == 2)
        det = key_matrix[0][0]*key_matrix[1][1] - key_matrix[0][1]*key_matrix[1][0];
    if (k == 3)
        det = key_matrix[0][0] * (key_matrix[1][1]*key_matrix[2][2] - key_matrix[1][2]*key_matrix[2][1]) -
              key_matrix[0][1] * (key_matrix[1][0]*key_matrix[2][2] - key_matrix[2][0]*key_matrix[1][2]) +
              key_matrix[0][2] * (key_matrix[1][0]*key_matrix[2][1] - key_matrix[1][1]*key_matrix[2][0]);
    if (det == 0) exit(84);

    if (k == 1) //calculate the inverse of the matrixes
        key_matrix[0][0] = 1 / key_matrix[0][0];
    if (k == 2)
        key_matrix[0][0] = key_matrix[1][1] / det, key_matrix[0][1] = -key_matrix[0][1] / det,
        key_matrix[1][0] = -key_matrix[1][0] / det, key_matrix[1][1] = key_matrix[0][0] / det;
    if (k == 3) {
        comatrix[0][0] = +(key_matrix[1][1]*key_matrix[2][2] - key_matrix[1][2]*key_matrix[2][1]);
        comatrix[0][1] = -(key_matrix[1][0]*key_matrix[2][2] - key_matrix[1][2]*key_matrix[0][0]);
        comatrix[0][2] = +(key_matrix[1][0]*key_matrix[2][1] - key_matrix[1][1]*key_matrix[2][0]);
        comatrix[1][0] = -(key_matrix[0][1]*key_matrix[2][2] - key_matrix[0][2]*key_matrix[2][1]);
        comatrix[1][1] = +(key_matrix[0][0]*key_matrix[2][2] - key_matrix[0][2]*key_matrix[2][0]);
        comatrix[1][2] = -(key_matrix[0][0]*key_matrix[2][1] - key_matrix[0][1]*key_matrix[2][0]);
        comatrix[2][0] = +(key_matrix[0][1]*key_matrix[1][2] - key_matrix[0][2]*key_matrix[1][1]);
        comatrix[2][1] = -(key_matrix[0][0]*key_matrix[1][2] - key_matrix[0][2]*key_matrix[1][0]);
        comatrix[2][2] = +(key_matrix[0][0]*key_matrix[1][1] - key_matrix[0][1]*key_matrix[1][0]);
        for (int a = 0; a != k; a++) {
            for (int b = 0; b != j; b++) {
                key_matrix[a][b] = comatrix[b][a];
                key_matrix[a][b] /= det;
            }
        }
    }

    for (int a = 0; a != i; a++) { //multiply the matrices
        for (int b = 0; b != j; b++) {
            decrypted_matrix[a][b] = 0;
            for (int c = 0; c != k; c++) {
                decrypted_matrix[a][b] += message_matrix[a][c] * key_matrix[c][b];
            }
        }
    }

    printf("Key matrix:\n");  //prints
    for (int a = 0; a != k; a++) {
        for (int b = 0; b != j; b++) {
            if (key_matrix[a][b] != 0)
                printf((b < j - 1 ? "%.3f\t" : "%.3f"), key_matrix[a][b]);
            else
                printf((b < j - 1 ? "%.1f\t" : "%.1f"), key_matrix[a][b]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Decrypted message:\n");
    for (int a = 0; a != i; a++) {
        for (int b = 0; b != k; b++)
            printf("%c", decrypted_matrix[a][b]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    if (argc < 4 || argc > 4) exit(84);
    if (argv[3][0] == '0' && argv[3][1] == '\0')
        encrypt(argv);
    else if (argv[3][0] == '1' && argv[3][1] == '\0')
        decrypt(argv);
    else
        exit(84);
    return (0);
}