/*
** EPITECH PROJECT, 2022
** False.hpp
** File description:
** False
*/

#include "False.hpp"

False::False(const std::string &name)
{
    _name = name;
    _pins.push_back(std::make_shared<Pin>(0, Pin::F));
    _pins[0]->setState(FALSE);
}