/*
** EPITECH PROJECT, 2022
** C4001.hpp
** File description:
** C4001
*/

#include "C4008.hpp"

C4008::C4008(const std::string &name)
{
    _name = name;
    for (size_t i = 0; i < 16; i++) {
        if (i == 7 || i == 15)
            _pins.push_back(std::make_shared<Pin>(i, Pin::U));
        else if (i > 8 && i < 14)
            _pins.push_back(std::make_shared<Pin>(i, Pin::O));
        else
            _pins.push_back(std::make_shared<Pin>(i, Pin::I));
    }
}

Tristate C4008::compute(size_t pin)
{
    if (pin == 13)
        return _pins[pin]->getState(); //TODO
    else if (pin == 12)
        return _xor(_xor(_pins[15]->getState(), _pins[0]->getState()), _pins[8]->getState());
    else if (pin == 11)
        return _xor(_xor(_pins[1]->getState(), _pins[2]->getState()), _pins[8]->getState());
    else if (pin == 10)
        return _xor(_xor(_pins[3]->getState(), _pins[4]->getState()), _pins[8]->getState());
    return _xor(_xor(_pins[5]->getState(), _pins[6]->getState()), _pins[8]->getState());
}