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

int main(void)
{
    std::string input;
    std::string temperature;

    getline(std::cin, input);
    temperature = input.substr(0, input.find(' '));
    std::cout << std::fixed;
    std::cout << std::setprecision(3);
    if (input.find("Celsius") != std::string::npos)
        std::cout << std::setw(16) << (9.0 / 5.0) * std::stof(temperature) + 32
             << std::setw(16) << "Fahrenheit" << std::endl;
    if (input.find("Fahrenheit") != std::string::npos)
        std::cout << std::setw(16) << (5.0 / 9.0) * (std::stof(temperature) - 32)
             << std::setw(16) << "Celsius" << std::endl;
    return 0;
}
