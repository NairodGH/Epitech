/*
** EPITECH PROJECT, 2022
** main.cpp
** File description:
** main
*/

#include "groundhog.hpp"
#include "error.hpp"

int main(int ac, char **av)
{
    groundhog groundhog;
    
    try {
        if (ac != 2)
            throw error("Provide only the required period");
        else if (av[1] == std::string("-h"))
            std::cout << "SYNOPSIS\n\t./groundhog period\n\nDESCRIPTION\n\tperiod\tthe number of days defining a period" << std::endl;
        else if (!groundhog.set_period(av[1]))
            throw error("Invalid period");
        else {
            std::cout << std::fixed;
            for (std::string input;;) {
                std::getline(std::cin, input);
                if (input == "STOP")
                    break;
                if (!groundhog.add_input(groundhog.get_input(input)))
                    throw error("Argument given is not a valid temperature");
                std::cout << std::setprecision(2) << "g=";
                if (groundhog.get_size() <= groundhog.get_period())
                    std::cout << "nan";
                else
                    std::cout << groundhog.temperature_increase_average();
                std::cout << std::setprecision(0) << "\tr=";
                if (groundhog.get_size() <= groundhog.get_period())
                    std::cout << "nan";
                else
                    std::cout << +groundhog.relative_temperature_evolution();
                std::cout << std::setprecision(2) << "%\ts=";
                if (groundhog.get_size() < groundhog.get_period())
                    std::cout << "nan";
                else
                    std::cout << groundhog.standard_deviation();
                if (groundhog.get_size() > groundhog.get_period() + 1 &&
                    !isinf(groundhog.get_evolution()) && !isinf(groundhog.get_previous_evolution())
                    && !isnan(groundhog.get_evolution()) && !isnan(groundhog.get_previous_evolution())
                    && (groundhog.get_evolution() < 0 && groundhog.get_previous_evolution() >= 0 ||
                    groundhog.get_evolution() >= 0 && groundhog.get_previous_evolution() < 0)) {
                    groundhog.set_switches(groundhog.get_switches() + 1);
                    std::cout << "\ta switch occurs";
                }
                std::cout << std::endl;
            }
            std::cout << "Global tendency switched " << groundhog.get_switches() << " times" << std::endl;
            if (groundhog.get_size() >= 5) {
                std::cout << "5 weirdest values are [" <<
                groundhog.get_input(groundhog.pop_highest_diff()) << ", " <<
                groundhog.get_input(groundhog.pop_highest_diff()) << ", " <<
                groundhog.get_input(groundhog.pop_highest_diff()) << ", " <<
                groundhog.get_input(groundhog.pop_highest_diff()) << ", " <<
                groundhog.get_input(groundhog.pop_highest_diff()) << "]" << std::endl;
            }
            else
                throw error("Not enough values entered to display the weirdest 5 ones");
        }
    }
    catch (const error &err) {
        std::cerr << "[ERROR] " << err.what() << std::endl;
        return 84;
    }
    return 0;
}