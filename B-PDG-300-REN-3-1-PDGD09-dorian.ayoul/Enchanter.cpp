/*
** EPITECH PROJECT, 2022
** Enchanter.cpp
** File description:
** Enchanter
*/

#include "Enchanter.hpp"

Enchanter::Enchanter(const std::string &name, int power) : Peasant(name, power)
{
    this->_name = name;
    this->_power = power;
    this->_hp = 100;
    std::cout << _name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << _name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    if (!_hp) {
        std::cout << _name << " is out of combat." << std::endl;
        return 0;
    }
    std::cout << _name << " doesn't know how to fight." << std::endl;
    return 0;
}

int Enchanter::special()
{
    if (!_hp) {
        std::cout << _name << " is out of combat." << std::endl;
        return 0;
    }
    if (_power < 50) {
        std::cout << _name << " is out of power." << std::endl;
        return 0;
    }
    _power -= 50;
    std::cout << _name << " casts a fireball." << std::endl;
    return 99;
}

void Enchanter::rest()
{
    if (!_hp) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    _power = 100;
    std::cout << _name << " meditates." << std::endl;
}