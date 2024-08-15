/*
** EPITECH PROJECT, 2022
** C2716.hpp
** File description:
** C2716
*/

#include "C2716.hpp"

C2716::C2716(const std::string &name)
{
    _name = name;
    for (size_t i = 0; i < 24; i++) {
        if (i > 7 && i < 17 && i != 11)
            _pins.push_back(std::make_shared<Pin>(i, Pin::O));
        else
            _pins.push_back(std::make_shared<Pin>(i, Pin::I));
    }
}

Tristate C2716::compute(size_t pin)
{
    return _pins[pin]->getState(); //TODO
}