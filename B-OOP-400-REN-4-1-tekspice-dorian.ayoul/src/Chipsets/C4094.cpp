/*
** EPITECH PROJECT, 2022
** C4094.hpp
** File description:
** C4094
*/

#include "C4094.hpp"

C4094::C4094(const std::string &name)
{
    _name = name;
    for (size_t i = 0; i < 16; i++) {
        if (i == 7 || i == 15)
            _pins.push_back(std::make_shared<Pin>(i, Pin::U));
        else if (i < 3 || i == 14)
            _pins.push_back(std::make_shared<Pin>(i, Pin::I));
        else
            _pins.push_back(std::make_shared<Pin>(i, Pin::O));
    }
}

Tristate C4094::compute(size_t pin)
{
    return _pins[pin]->getState(); //TODO
}