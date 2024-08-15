/*
** EPITECH PROJECT, 2022
** Knight.cpp
** File description:
** Knight
*/

#include "Knight.hpp"

Knight::Knight(const std::string &name, int power) : Peasant(name, power)
{
    this->_name = name;
    this->_power = power;
    this->_hp = 100;
    std::cout << _name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << _name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    if (!_hp) {
        std::cout << _name << " is out of combat." << std::endl;
        return 0;
    }
    if (_power < 10) {
        std::cout << _name << " is out of power." << std::endl;
        return 0;
    }
    _power -= 10;
    std::cout << _name << " strikes with his sword." << std::endl;
    return 20;
}

int Knight::special()
{
    if (!_hp) {
        std::cout << _name << " is out of combat." << std::endl;
        return 0;
    }
    if (_power < 30) {
        std::cout << _name << " is out of power." << std::endl;
        return 0;
    }
    _power -= 30;
    std::cout << _name << " impales his enemy." << std::endl;
    return 50;
}

void Knight::rest()
{
    if (!_hp) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    if (_power <= 50)
        _power += 50;
    else
        _power = 100;
    std::cout << _name << " eats." << std::endl;
}