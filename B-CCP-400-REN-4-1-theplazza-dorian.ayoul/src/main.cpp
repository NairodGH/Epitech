/*
** EPITECH PROJECT, 2022
** main.cpp
** File description:
** main
*/

#include "includes.hpp"
#include "Parser.hpp"
#include "Error.hpp"
#include "Reception.hpp"

using namespace plz;

int main(int ac, char **av)
{
    try {
        Parser parser(ac, av);
        Reception reception(parser);
    }
    catch (const Error &err) {
        std::cerr << "\033[1;31m[ERROR]\033[0m " << err.what() << std::endl;
        return 84;
    }
    return 0;
}
