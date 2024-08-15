/*
** EPITECH PROJECT, 2022
** C4801.hpp
** File description:
** C4801
*/

#include "C4801.hpp"

C4801::C4801(const std::string &name)
{
    _name = name;
    for (size_t i = 0; i < 24; i++) {
        if (i == 11 || i == 18 || i == 23)
            _pins.push_back(std::make_shared<Pin>(i, Pin::U));
        else if (i > 7 && i < 17 && i != 11)
            _pins.push_back(std::make_shared<Pin>(i, Pin::O));
        else
            _pins.push_back(std::make_shared<Pin>(i, Pin::I));
    }
}

Tristate C4801::compute(size_t pin)
{
    return _pins[pin]->getState(); //TODO
}