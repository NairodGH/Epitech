/*
** EPITECH PROJECT, 2022
** C4514.hpp
** File description:
** C4514
*/

#include "C4514.hpp"

C4514::C4514(const std::string &name)
{
    _name = name;
    for (size_t i = 0; i < 24; i++) {
        if (i == 11 || i == 23)
            _pins.push_back(std::make_shared<Pin>(i, Pin::U));
        else if (i < 3 || (i > 19 && i < 23))
            _pins.push_back(std::make_shared<Pin>(i, Pin::I));
        else
            _pins.push_back(std::make_shared<Pin>(i, Pin::O));
    }
}

Tristate C4514::compute(size_t pin)
{
    return _pins[pin]->getState(); //TODO
}