/*
** EPITECH PROJECT, 2022
** 307multigrains.cpp
** File description:
** 307multigrains.cpp
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

static const std::string seeds[5] = {"Oat", "Wheat", "Corn", "Barley", "Soy"};

int main(int ac, char **av)
{
    if (ac != 10)
        return 84;
    for (size_t i = 1; i < ac; i++)
        for (size_t j = 0; av[i][j]; j++)
            if (!(av[i][j] >= '0' && av[i][j] <= '9' || av[i][j] == '.'))
                return 84;

    std::vector<std::vector<double>> m = {
        {1, 0, 1, 0, 2, 1, 0, 0, 0, 0, atof(av[1])},
        {1, 2, 0, 1, 0, 0, 1, 0, 0, 0, atof(av[2])},
        {2, 1, 0, 1, 0, 0, 0, 1, 0, 0, atof(av[3])},
        {0, 0, 3, 1, 2, 0, 0, 0, 1, 0, atof(av[4])},
        {-atof(av[5]), -atof(av[6]), -atof(av[7]), -atof(av[8]), -atof(av[9]), 0, 0, 0, 0, 1, 0},
    };
    double tmp;
    // for (auto vec: m) {
    //     for (auto val: vec)
    //         std::cout << val << "\t";
    //     std::cout << "\n";
    // }
    // std::cout << "\n";
    for (size_t i = 0; i < 5; i++) {
        size_t x = std::distance(m[4].begin(), std::min_element(m[4].begin(), std::next(m[4].begin(), 5)));
        size_t y = std::distance(m.begin(), std::min_element(m.begin(), std::next(m.begin(), 4), [&](const std::vector<double>& v1, const std::vector<double>& v2){return (v1[x] > 0 ? v1[10] / v1[x] : DBL_MAX) < (v2[x] > 0 ? v2[10] / v2[x] : DBL_MAX);}));
        // std::cout << "x = " << x << " y = " << y << "\n";
        tmp = m[y][x];
        for (size_t j = 0; j < 11; j++)
            m[y][j] /= tmp;
        for (size_t j = 0; j < 5; j++) {
            if (j == y)
                continue;
            tmp = m[j][x];
            for (size_t k = 0; k < 11; k++)
                m[j][k] -= tmp * m[y][k];
        }
        // std::cout << "m =\n";
        // for (auto vec: m) {
        //     for (auto val: vec)
        //         std::cout << std::fixed << std::setprecision(2) << val << "\t";
        //     std::cout << "\n";
        // }
        // std::cout << "\n";
    }

    std::cout << "Resources: ";
    for (size_t i = 1; i < 5; i++)
        std::cout << av[i] << " F" << i << (i == 4 ? "\n\n" : ", ");
    for (size_t i = 0; i < 5; i++) {
        std::cout << seeds[i] << ": ";
        if (m[4][i] || !m[4][10])
            std::cout << "0";
        else {
            if (std::find_if(m.begin(), m.end(), [&](const std::vector<double>& v){return v[i] == 1;}) == m.end() || !atof(av[i + 5]))
                tmp = 0;
            else
                tmp = m[std::distance(m.begin(), std::find_if(m.begin(), m.end(), [&](const std::vector<double>& v){return v[i] == 1;}))][10];
            std::cout << std::fixed << std::setprecision(tmp ? 2 : 0) << tmp;
        }
        std::cout << " units at $" << av[i + 5] << "/unit\n";
    }
    std::cout << "\nTotal production value: $" << std::fixed << std::setprecision(2) << m[4][10] << "\n";
    return 0;
}