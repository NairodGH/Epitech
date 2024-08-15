/*
** EPITECH PROJECT, 2022
** Fruit.cpp
** File description:
** Fruit
*/

#include "Fruit.hpp"

Fruit::Fruit(int vitamins, const std::string name)
{
    _vitamins = vitamins;
    _name = name;
}

int Fruit::getVitamins() const
{
    return _vitamins;
}

const std::string Fruit::getName() const
{
    return _name;
}