/*
** EPITECH PROJECT, 2022
** Input.hpp
** File description:
** Input
*/

#include "Input.hpp"

Input::Input(const std::string &name)
{
    _name = name;
    _pins.push_back(std::make_shared<Pin>(0, Pin::I));
}