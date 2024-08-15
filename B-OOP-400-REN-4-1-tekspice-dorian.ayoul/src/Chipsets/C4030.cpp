/*
** EPITECH PROJECT, 2022
** C4030.hpp
** File description:
** C4030
*/

#include "C4030.hpp"

C4030::C4030(const std::string &name)
{
    _name = name;
    for (size_t i = 0; i < 14; i++) {
        if (i == 6 || i == 13)
            _pins.push_back(std::make_shared<Pin>(i, Pin::U));
        else if (i == 2 || i == 3 || i == 9 || i == 10)
            _pins.push_back(std::make_shared<Pin>(i, Pin::O));
        else
            _pins.push_back(std::make_shared<Pin>(i, Pin::I));
    }
}

Tristate C4030::compute(size_t pin)
{
    return _xor(_pins[pin + (pin % 2 ? 2 : -2)]->getState(), _pins[pin + (pin % 2 ? 1 : -1)]->getState());
}