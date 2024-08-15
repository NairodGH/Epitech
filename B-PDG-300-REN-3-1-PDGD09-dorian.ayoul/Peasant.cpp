/*
** EPITECH PROJECT, 2022
** Peasant.cpp
** File description:
** Peasant
*/

#include "Peasant.hpp"

Peasant::Peasant(const std::string &name, int power)
{
    this->_name = name;
    this->_power = power;
    this->_hp = 100;
    std::cout << _name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << _name << " is back to his crops." << std::endl;
}

const std::string &Peasant::getName() const
{
    return _name;
}

int Peasant::getPower() const
{
    return _power;
}

int Peasant::getHp() const
{
    return _hp;
}

int Peasant::attack()
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
    std::cout << _name << " tosses a stone." << std::endl;
    return 5;
}

int Peasant::special()
{
    if (!_hp) {
        std::cout << _name << " is out of combat." << std::endl;
        return 0;
    }
    std::cout << _name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest()
{
    if (!_hp) {
        std::cout << _name << " is out of combat." << std::endl;
        return;
    }
    if (_power <= 70)
        _power += 30;
    else
        _power = 100;
    std::cout << _name << " takes a nap." << std::endl;
}

void Peasant::damage(int damage)
{
    _hp -= damage;
    if (_hp > 0)
        std::cout << _name << " takes " << damage << " damage." << std::endl;
    else {
        _hp = 0;
        std::cout << _name << " is out of combat." << std::endl;
    }
}

void Peasant::drink(const IPotion &potion)
{
    std::cout << _name << " drinks a mysterious potion." << std::endl;
    _hp += potion.getHp();
    _power += potion.getPower();
    if (_hp > 100)
        _hp = 100;
    if (_power > 100)
        _power = 100;
    if (_hp < 0)
        _hp = 0;
}

void Peasant::drink(const HealthPotion &potion)
{
    std::cout << _name << " feels rejuvenated." << std::endl;
    _hp += potion.getHp();
    if (_hp > 100)
        _hp = 100;
}

void Peasant::drink(const PowerPotion &potion)
{
    std::cout << _name << "'s power is restored." << std::endl;
    _power += potion.getPower();
    if (_power > 100)
        _power = 100;
}

void Peasant::drink(const PoisonPotion &potion)
{
    std::cout << _name << " has been poisoned." << std::endl;
    _hp += potion.getHp();
    if (_hp < 0)
        _hp = 0;
}