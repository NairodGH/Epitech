/*
** EPITECH PROJECT, 2022
** Priest.cpp
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int power) : Peasant(name, power), Enchanter(name, power)
{
    this->_name = name;
    this->_power = power;
    this->_hp = 100;
    std::cout << _name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << _name << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (!_hp) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    _power = 100;
    _hp = 100;
    std::cout << _name << " prays." << std::endl;
}