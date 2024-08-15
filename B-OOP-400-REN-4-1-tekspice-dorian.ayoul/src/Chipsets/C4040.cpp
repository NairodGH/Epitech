/*
** EPITECH PROJECT, 2022
** C4040.hpp
** File description:
** C4040
*/

#include "C4040.hpp"

C4040::C4040(const std::string &name)
{
    _name = name;
    for (size_t i = 0; i < 16; i++) {
        if (i == 7 || i == 15)
            _pins.push_back(std::make_shared<Pin>(i, Pin::U));
        else if (i == 9 || i == 10)
            _pins.push_back(std::make_shared<Pin>(i, Pin::I));
        else
            _pins.push_back(std::make_shared<Pin>(i, Pin::O));
    }
}

Tristate C4040::compute(size_t pin)
{
    return _pins[pin]->getState(); //TODO
}