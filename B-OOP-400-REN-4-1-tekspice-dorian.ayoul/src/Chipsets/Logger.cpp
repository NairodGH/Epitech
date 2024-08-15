/*
** EPITECH PROJECT, 2022
** Logger.hpp
** File description:
** Logger
*/

#include "Logger.hpp"

Logger::Logger(const std::string &name)
{
    _name = name;
    for (size_t i = 0; i < 10; i++)
        _pins.push_back(std::make_shared<Pin>(i, Pin::I));
}

Tristate Logger::compute(size_t pin)
{
    return _pins[pin]->getState(); //TODO
}