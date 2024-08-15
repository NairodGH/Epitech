/*
** EPITECH PROJECT, 2022
** main.cpp
** File description:
** main
*/

#include "Error.hpp"
#include "core.hpp"

int main(int ac, char **av)
{
    try {
        if (ac != 2)
            throw arc::Error("No initial graphic library provided.");
        arc::Core core(av[1]);
    }
    catch (const arc::Error &err) {
        std::cerr << "[ERROR] " << err.what() << std::endl;
        return 84;
    }
    return 0;
}
