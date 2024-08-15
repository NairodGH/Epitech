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

void Buzz::speak(const std::string statement)
{
    std::cout << "BUZZ:" << _name << " \"" << statement << "\"" << std::endl;
}

bool Buzz::speak_es(const std::string statement)
{
	std::cout << "BUZZ: " << _name << " senorita \"" << statement << "\" senorita" << std::endl;
	return true;
}