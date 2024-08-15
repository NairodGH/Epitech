/*
** EPITECH PROJECT, 2022
** Buzz.cpp
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &filename) : Toy(BUZZ, name, filename)
{
}

Buzz::Buzz(const Buzz &buzz) : Toy(buzz)
{
}