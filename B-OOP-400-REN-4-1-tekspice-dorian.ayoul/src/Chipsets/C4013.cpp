/*
** EPITECH PROJECT, 2022
** C4013.hpp
** File description:
** C4013
*/

#include "C4013.hpp"

C4013::C4013(const std::string &name)
{
    _name = name;
    for (size_t i = 0; i < 14; i++) {
        if (i == 6 || i == 13)
            _pins.push_back(std::make_shared<Pin>(i, Pin::U));
        else if (i == 0 || i == 1 || i == 11 || i == 12)
            _pins.push_back(std::make_shared<Pin>(i, Pin::O));
        else
            _pins.push_back(std::make_shared<Pin>(i, Pin::I));
    }
}

Tristate C4013::compute(size_t pin)
{
    return _pins[pin]->getState(); //TODO
}