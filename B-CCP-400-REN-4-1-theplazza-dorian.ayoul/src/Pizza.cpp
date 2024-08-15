/*
** EPITECH PROJECT, 2022
** Pizza.cpp
** File description:
** Pizza
*/

#include "Pizza.hpp"

using namespace plz;

Pizza::Pizza(PizzaType type, PizzaSize size, size_t id) : _type(type), _size(size), _id(id), _nbOrdered(0)
{
}

PizzaType Pizza::getType()
{
    return _type;
}

void Pizza::setType(PizzaType type)
{
    _type = type;
}

PizzaSize Pizza::getSize()
{
    return _size;
}

void Pizza::setSize(PizzaSize size)
{
    _size = size;
}

size_t Pizza::getNbOrdered()
{
    return _nbOrdered;
}

void Pizza::setNbOrdered(size_t nbOrdered)
{
    _nbOrdered = nbOrdered;
}


size_t Pizza::getId()
{
    return _id;
}

void Pizza::setId(size_t id)
{
    _id = id;
}
