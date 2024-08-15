/*
** EPITECH PROJECT, 2022
** 302separation.cpp
** File description:
** 302separation.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

std::vector<std::vector<size_t>> pow(std::vector<std::vector<size_t>> matrix, size_t n)
{
    std::vector<std::vector<size_t>> tmp(matrix);
    std::vector<std::vector<size_t>> copy(matrix);
    size_t size = matrix.size();

    for (size_t h = 0; h < n; h++) {
        for (auto &vector: tmp)
            std::fill(vector.begin(), vector.end(), 0);
        for (size_t i = 0; i < size; i++)
            for (size_t j = 0; j < size; j++)
                for (size_t k = 0; k < size; k++)
                    tmp[i][j] += copy[i][k] * matrix[k][j];
        copy = tmp;
    }
    return copy;
}

int main(int ac, char **av)
{
    if (ac != 3 && ac != 4)
        return 84;
    
    std::ifstream file(av[1]);
    std::map<std::string, std::vector<size_t>> list;
    if (file.is_open()) {
        for (std::string line; std::getline(file, line);) {
            if (line.find(" is friends with ") != std::string::npos &&
                !line.substr(0, line.find(" is friends with ")).empty() &&
                !line.substr(line.find(" is friends with ") + 17).empty())
                list[line.substr(0, line.find(" is friends with "))] = list[line.substr(line.find(" is friends with ") + 17)] = std::vector<size_t>();
            else
                return 84;
        }
        file.clear();
        file.seekg(0);
        for (std::string line, tmp1, tmp2; std::getline(file, line);) {
            tmp1 = line.substr(0, line.find(" is friends with "));
            tmp2 = line.substr(line.find(" is friends with ") + 17);
            if (list[tmp1].empty())
                list[tmp1] = std::vector<size_t>(list.size(), 0);
            list[tmp1][std::distance(std::begin(list), list.find(tmp2))] = 1;
            if (list[tmp2].empty())
                list[tmp2] = std::vector<size_t>(list.size(), 0);
            list[tmp2][std::distance(std::begin(list), list.find(tmp1))] = 1;
        }
        if (list.empty())
            return 84;

        size_t n = 0;
        if (ac == 3) {
            for (size_t i = 0; av[2][i] != '\0'; i++)
                if (!(av[2][i] >= '0' && av[2][i] <= '9'))
                    return 84;
            if (!(n = std::strtoul(av[2], NULL, 0)))
                return 84;
            for (auto const &pair: list)
                std::cout << pair.first << (pair.first == list.rbegin()->first ? "\n\n" : "\n");
            for (auto const &pair: list) {
                for (size_t i = 0; i < pair.second.size(); i++)
                    std::cout << pair.second[i] << (i == pair.second.size() - 1 ? "" : " ");
                std::cout << (pair.first == list.rbegin()->first ? "\n\n" : "\n");
            }
        }
        std::vector<std::vector<size_t>> matrix;
        for (auto const &pair: list)
            matrix.push_back(pair.second);
        size_t size = matrix.size();
        std::vector<std::vector<size_t>> result(matrix);
        for (size_t h = 1; h < (ac == 3 ? n : list.size()); h++) {
            std::vector<std::vector<size_t>> tmp(pow(matrix, h));
            for (size_t i = 0; i < size; i++)
                for (size_t j = 0; j < size; j++)
                    if (i != j && !result[i][j] && tmp[i][j])
                        result[i][j] = h + 1;
        }
        if (ac == 3) {
            for (auto const &vector: result) {
                for (size_t i = 0; i < size; i++)
                    std::cout << vector[i] << (i == size - 1 ? "" : " ");
                std::cout << std::endl;
            }
        }
        if (ac == 4) {
            std::cout << "Degree of separation between " << av[2] << " and " << av[3] << ": ";
            if (!list.count(av[2]) || !list.count(av[3]) || std::string(av[2]) != std::string(av[3]) &&
                !result[std::distance(std::begin(list), list.find(av[2]))][std::distance(std::begin(list), list.find(av[3]))])
                std::cout << -1 << std::endl;
            else
                std::cout << result[std::distance(std::begin(list), list.find(av[2]))][std::distance(std::begin(list), list.find(av[3]))] << std::endl;
        }
        file.close();
    }
    else
        return 84;
    return 0;
}