/*
** EPITECH PROJECT, 2022
** True.hpp
** File description:
** True
*/

#include "True.hpp"

True::True(const std::string &name)
{
    _name = name;
    _pins.push_back(std::make_shared<Pin>(0, Pin::T));
    _pins[0]->setState(TRUE);
}