/*
** EPITECH PROJECT, 2022
** Toy.cpp
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(ToyType type, const std::string &name, const std::string &ascii)
{
    _type = type;
    _name = name;
    _ascii = ascii;
}

Toy::Toy(const Toy &cpy)
{
    this->_type = cpy._type;
    this->_name = cpy._name;
    this->_ascii = cpy._ascii;
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

const std::string &Toy::getName() const
{
    return _name;
}

const std::string &Toy::getAscii() const
{
    return _ascii.data;
}

void Toy::setName(const std::string &name)
{
    _name = name;
}

bool Toy::setAscii(const std::string &ascii)
{
    return _ascii.getPictureFromFile(ascii);
}

Toy &Toy::operator=(const Toy &cpy)
{
    _type = cpy._type;
    _name = cpy._name;
    _ascii = cpy._ascii;
    return *this;
}