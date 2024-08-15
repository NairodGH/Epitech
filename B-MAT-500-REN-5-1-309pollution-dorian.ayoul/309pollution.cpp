/*
** EPITECH PROJECT, 2022
** 309pollution.cpp
** File description:
** 309pollution.cpp
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

typedef struct {
    size_t x;
    size_t y;
    size_t p;
} pollution_t;

double factorial(double n) {
    return (n == 1.0 || n == 0.0) ? 1.0 : n * factorial(n - 1.0);
}

int main(int ac, char **av)
{
    if (ac != 5)
        return 84;

    std::vector<double> params;
    for (size_t i = 1; i < ac; i++) {
        if (i == 2)
            continue;
        for (size_t j = 0; av[i][j]; j++)
            if (!(av[i][j] >= '0' && av[i][j] <= '9' || av[i][j] == '.' && i > 2))
                return 84;
        params.push_back(atof(av[i]));
    }
    if (!params[0] || params[1] * params[0] + params[2] > std::pow(params[0], 2) - 1)
        return 84;

    std::ifstream file(av[2]);
    std::vector<pollution_t> csv;
    std::vector<std::vector<size_t>> m(params[0], std::vector<size_t>(params[0]));
    if (file.is_open()) {
        for (std::string line; std::getline(file, line);) {
            for (const auto &c: line)
                if (!(c >= '0' && c <= '9' || c == ';'))
                    return 84;
            size_t x = stoull(line.substr(0, line.find_first_of(';')));
            size_t y = stoull(line.substr(line.find_first_of(';') + 1, line.find_last_of(';') - line.find_first_of(';') - 1));
            m[x][y] = stoull(line.substr(line.find_last_of(';') + 1));
        }
        double res = 0;
        for (size_t k1 = 0; k1 < params[0]; k1++) {
            for (size_t k2 = 0; k2 < params[0]; k2++) {
                res +=
                    (factorial(params[0] - 1) / (factorial(k1) * factorial(params[0] - 1 - k1))) *
                    (factorial(params[0] - 1) / (factorial(k2) * factorial(params[0] - 1 - k2))) *
                    pow(params[1] / (params[0] - 1.0), k1) *
                    pow(1.0 - (params[1] / (params[0] - 1.0)), params[0] - k1 - 1.0) *
                    pow(params[2] / (params[0] - 1.0), k2) *
                    pow(1.0 - (params[2] / (params[0] - 1.0)), params[0] - k2 - 1.0) *
                    m[k1][k2];
            }
        }
        std::cout << std::fixed << std::setprecision(2) << res << std::endl;
    }
    else
        return 84;
    return 0;
}
