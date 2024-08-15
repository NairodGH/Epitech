/*
** EPITECH PROJECT, 2022
** Clock.hpp
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock(const std::string &name)
{
    _name = name;
    _pins.push_back(std::make_shared<Pin>(0, Pin::I));
}