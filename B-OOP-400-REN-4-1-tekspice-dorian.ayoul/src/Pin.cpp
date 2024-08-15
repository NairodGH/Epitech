/*
** EPITECH PROJECT, 2022
** Pin.cpp
** File description:
** Pin
*/

#include <iostream>
#include "Pin.hpp"

Pin::Pin(size_t pin, Type type, Tristate state)
{
    _nb = pin;
    _type = type;
    _state = state;
    _link = nullptr;
    _clock = UNDEFINED;
}

Pin::Type Pin::getType()
{
    return _type;
}

void Pin::setType(Pin::Type type)
{
    _type = type;
}

Tristate Pin::getState()
{
    return _state;
}

void Pin::setState(Tristate state)
{
    _state = state;
}

std::shared_ptr<Pin> &Pin::getLink()
{
    return _link;
}

void Pin::setLink(std::shared_ptr<Pin> &pin)
{
    this->_link = pin;
}

Tristate Pin::getClock()
{
    return _clock;
}

void Pin::setClock(Tristate clock)
{
    this->_clock = clock;
}