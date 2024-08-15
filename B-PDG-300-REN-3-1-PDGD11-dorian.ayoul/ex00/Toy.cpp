/*
** EPITECH PROJECT, 2022
** Toy.cpp
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(ToyType type, std::string name, std::string ascii)
{
    _type = type;
    _name = name;
    _ascii = ascii;
}

Toy::Toy()
{
    _type = BASIC_TOY;
    _name = "toy";
    _ascii.data = "";
}

Toy::ToyType Toy::getType() const
{
    return _type;
}

std::string Toy::getName() const
{
    return _name;
}

std::string Toy::getAscii() const
{
    return _ascii.data;
}

void Toy::setName(std::string name)
{
    _name = name;
}

bool Toy::setAscii(std::string ascii)
{
    return _ascii.getPictureFromFile(ascii);
}