/*
** EPITECH PROJECT, 2022
** main.cpp
** File description:
** main
*/

#include "Parser.hpp"

int main(int ac, char **av)
{
    std::string input;
    Parser parser;
    Circuit circuit;

    std::cin.exceptions(std::ifstream::failbit);
    try {
        if (ac != 2 || std::string(av[1]).find(".nts") == std::string::npos)
            throw Error("Provide only the .nts file");
        parser.parseFile(av[1]);
        while (input != "exit") {
            std::cout << "> ";
            try {
                std::getline(std::cin, input);
            }
            catch(std::ifstream::failure &err) {
                return 0;
            }
            if (input != "" && input != "exit")
                parser.checkCommand(input, circuit);
        }
    }
    catch (const std::exception &err) {
        std::cerr << "[ERROR] " << err.what() << std::endl;
        return 84;
    }
    return 0;
}