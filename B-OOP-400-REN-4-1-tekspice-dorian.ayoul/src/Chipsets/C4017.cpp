/*
** EPITECH PROJECT, 2022
** C4017.hpp
** File description:
** C4017
*/

#include "C4017.hpp"

C4017::C4017(const std::string &name)
{
    _name = name;
    for (size_t i = 0; i < 16; i++) {
        if (i == 7 || i == 15)
            _pins.push_back(std::make_shared<Pin>(i, Pin::U));
        else if (i > 11 && i < 15)
            _pins.push_back(std::make_shared<Pin>(i, Pin::I));
        else
            _pins.push_back(std::make_shared<Pin>(i, Pin::O));
    }
}

Tristate C4017::compute(size_t pin)
{
    return _pins[pin]->getState(); //TODO
}