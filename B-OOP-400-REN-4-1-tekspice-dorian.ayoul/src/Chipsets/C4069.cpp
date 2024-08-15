/*
** EPITECH PROJECT, 2022
** C4069.hpp
** File description:
** C4069
*/

#include "C4069.hpp"

C4069::C4069(const std::string &name)
{
    _name = name;
    for (size_t i = 0; i < 14; i++) {
        if (i == 6 || i == 13)
            _pins.push_back(std::make_shared<Pin>(i, Pin::U));
        else
            _pins.push_back(std::make_shared<Pin>(i, i % 2 ? Pin::O : Pin::I));
    }
}

Tristate C4069::compute(size_t pin)
{
    return _not(_pins[pin + (pin < 6 ? -1 : 1)]->getState());
}