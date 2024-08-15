/*
** EPITECH PROJECT, 2022
** main.cpp
** File description:
** main
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

int main(int ac, char const **av)
{
    std::ifstream file;

    if (ac == 1)
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
    for (size_t i = 1; av[i]; i++) {
        file.open(av[i]);
        if (!file.is_open())
            std::cerr << "my_cat: " << av[i] << ": No such file or directory" << std::endl;
        std::cout << file.rdbuf();
        file.close();
    }
    return 0;
}
