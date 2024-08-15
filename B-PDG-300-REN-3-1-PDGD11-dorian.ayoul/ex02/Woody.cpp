/*
** EPITECH PROJECT, 2022
** Woody.cpp
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(const std::string &name, const std::string &filename) : Toy(WOODY, name, filename)
{
}

Woody::Woody(const Woody &woody) : Toy(woody)
{
}