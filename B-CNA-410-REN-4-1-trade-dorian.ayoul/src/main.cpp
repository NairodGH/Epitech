/*
** EPITECH PROJECT, 2022
** main.cpp
** File description:
** main
*/

#include "Calculator.hpp"

int main(int ac, char **av)
{
    Calculator calc;
    string input;

    std::cout << std::setprecision(13) << std::fixed;
    while (1) {
        std::getline(std::cin, input);
        if (input.size() > 0) {
            if (input.find("settings") != std::string::npos)
                calc.set_setting(input);
            else if (input.find("next_candles") != std::string::npos)
                calc.set_candle(input);
            else if (input.find("stacks") != std::string::npos) {
                calc.get_settings().setBTC(std::stod(input.substr(input.find_first_of(':') + 1)));
                calc.get_settings().setUSDT(std::stod(input.substr(input.find_last_of(':') + 1)));
            }
            else if (input.find("action") != std::string::npos) {
                calc.act();
            }
        }
    }
    return 0;
}