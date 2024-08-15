/*
** EPITECH PROJECT, 2022
** Output.hpp
** File description:
** Output
*/

#include "Output.hpp"

Output::Output(const std::string &name)
{
    _name = name;
    _pins.push_back(std::make_shared<Pin>(0, Pin::O));
}