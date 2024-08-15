/*
** EPITECH PROJECT, 2022
** 308reedpipes.cpp
** File description:
** 308reedpipes.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cfloat>

const double h = 5.0; //constant difference between the abscissas of the params

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

double factorial(double n) {
    return (n == 1.0 || n == 0.0) ? 1.0 : n * factorial(n - 1.0);
}

int main(int ac, char **av)
{
    if (ac != 7)
        return 84;

    std::vector<double> params;
    for (size_t i = 1; i < ac; i++) {
        for (size_t j = 0; av[i][j]; j++)
            if (!(av[i][j] >= '0' && av[i][j] <= '9' || av[i][j] == '.' && i < 6))
                return 84;
        params.push_back(atof(av[i]));
        if (!params.back() || i == 6 && params.back() == 1)
            return 84;
    }

    std::vector<double> f_xi_xi1;
    for (size_t i = 0; i < params.size() - 2; i++)
        f_xi_xi1.push_back((params[i + 1] - params[i]) / 5.0);
    std::vector<double> f_xi_xi1_xi2;
    for (size_t i = 0; i < f_xi_xi1.size() - 1; i++)
        f_xi_xi1_xi2.push_back((f_xi_xi1[i + 1] - f_xi_xi1[i]) / 10.0);
    std::vector<std::vector<double>> B(5, std::vector<double>(1));
    for (size_t i = 0; i < f_xi_xi1_xi2.size(); i++)
        B[i + 1][0] = 6.0 * f_xi_xi1_xi2[i];
    std::vector<std::vector<double>> M =  {
        {1.0, 0, 0.0, 0.0, 0.0},
        {1.0 / 2.0, 2.0, 1.0 / 2.0, 0.0, 0.0},
        {0.0, 1.0 / 2.0, 2.0, 1.0 / 2.0, 0.0},
        {0.0, 0.0, 1.0 / 2.0, 2.0, 1.0 / 2.0},
        {0.0, 0.0, 0.0, 0.0, 1.0}
    };
    std::vector<std::vector<double>> V(multiply(inverse(M), B)); //V is f_2 aka f second derivative
    std::cout << "vector result: [";
    std::cout << std::fixed << std::setprecision(1);
    for (size_t i = 0; i < V.size(); i++)
        std::cout <<(-0.05 < V[i][0] && V[i][0] < 0.0 ? -V[i][0] : V[i][0]) << (i == V.size() - 1 ? "" : ", ");
    std::cout << "]\n";
    const double step = 20.0 / (params[5] - 1.0);
    for (double x = 0.0, f_1, f_3; x <= 20.04; x += step) {
        size_t i = floor((x >= 20.0 ? x - 0.04 : x) / 5.0); //avoid i == 4 which would segfault, git checkout a82d50d for the full (ugly) conditions
        std::cout << "abscissa: " << x << " cm\t radius: ";
        f_1 = f_xi_xi1[i] - ((h * V[i][0]) / 3.0) - ((h * V[i + 1][0]) / 6.0);
        f_3 = (V[i + 1][0] - V[i][0]) / h;
        std::cout << params[i] + (f_1 * (x - i * h)) + ((V[i][0] / factorial(2.0)) * pow(x - i * h, 2.0)) + ((f_3 / factorial(3.0)) * pow(x - i * h, 3.0));
        std::cout << " cm\n";
    }
    return 0;
}
