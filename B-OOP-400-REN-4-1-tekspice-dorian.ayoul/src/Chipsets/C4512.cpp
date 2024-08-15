/*
** EPITECH PROJECT, 2022
** C4512.hpp
** File description:
** C4512
*/

#include "C4512.hpp"

C4512::C4512(const std::string &name)
{
    _name = name;
    for (size_t i = 0; i < 16; i++) {
        if (i == 7 || i == 15)
            _pins.push_back(std::make_shared<Pin>(i, Pin::U));
        else if (i == 13)
            _pins.push_back(std::make_shared<Pin>(i, Pin::O));
        else
            _pins.push_back(std::make_shared<Pin>(i, Pin::I));
    }
}

Tristate C4512::compute(size_t pin)
{
    return _pins[pin]->getState(); //TODO
}