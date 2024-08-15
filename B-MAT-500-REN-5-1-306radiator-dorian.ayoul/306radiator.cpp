/*
** EPITECH PROJECT, 2022
** 306radiator.cpp
** File description:
** 306radiator.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

std::vector<std::vector<double>> multiply(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2)
{
    size_t n = matrix1.size();
    std::vector<std::vector<double>> result(n, std::vector<double>(1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][0] += matrix1[i][j] * matrix2[j][0];
    return result;
}

std::vector<std::vector<double>> inverse(std::vector<std::vector<double>> matrix)
{
    size_t n = matrix.size();
    std::vector<std::vector<double>> inverse(n, std::vector<double>(n));
    double pivot, factor;

    for (size_t i = 0; i < n; i++)
        inverse[i][i] = 1;
    for (size_t i = 0; i < n; i++) {
        pivot = matrix[i][i];
        for (size_t j = 0; j < n; j++) {
            matrix[i][j] /= pivot;
            inverse[i][j] /= pivot;
        }
        for (size_t j = 0; j < n; j++) {
            if (j != i) {
                factor = matrix[j][i];
                for (size_t k = 0; k < n; k++) {
                    matrix[j][k] -= matrix[i][k] * factor;
                    inverse[j][k] -= inverse[i][k] * factor;
                }
            }
        }
    }
    return inverse;
}

int main(int ac, char **av)
{
    if (!(ac == 4 || ac == 6))
        return 84;

    size_t n, ir, jr, ip, jp;
    for (size_t i = 1; i < ac; i++) {
        for (size_t j = 0; av[i][j]; j++)
            if (av[i][j] < '0' || av[i][j] > '9')
                return 84;
        if (i > 1 && (atoi(av[i]) < 1 || atoi(av[i]) > n - 2))
            return 84;
        (i == 1 ? n : i == 2 ? jr : i == 3 ? ir : i == 4 ? jp : ip) = atoi(av[i]);
    }
    if (n < 3)
        return 84;

    std::vector<std::vector<double>> A(n * n, std::vector<double>(n * n)), F(n * n, std::vector<double>(1));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (i && i != n - 1 && j && j != n - 1) {
                A[i * n + j][i * n + j] = -16;
                A[i * n + j][i * n + j - 1] = 4;
                A[i * n + j][i * n + j + 1] = 4;
                A[i * n + j][i * n + j - n] = 4;
                A[i * n + j][i * n + j + n] = 4;
            }
            else
                A[i * n + j][i * n + j] = 1;
        }
    }
    F[ir * n + jr][0] = -300;

    if (ac == 4) {
        for (auto const &vec: A) {
            for (size_t i = 0; i < n * n; i++)
                std::cout << vec[i] << (i == n * n - 1 ? "" : "\t");
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    F = multiply(inverse(A), F);
    for (size_t i = 0; i < n * n; i++)
        if (ac == 4 || ac == 6 && ip * n + jp == i)
            std::cout << std::fixed << std::setprecision(1) << std::round(F[i][0] * 10.0) / 10.0 << std::endl;
    return 0;
}