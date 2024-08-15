/*
** EPITECH PROJECT, 2022
** entryPoint.cpp
** File description:
** entryPoint
*/

#include "SFML.hpp"

arc::IDisplay *lib = nullptr;

__attribute__((constructor))
void loadLib()
{
	lib = new arc::SFML;
}

__attribute__((destructor))
void unloadLib()
{
	delete lib;
}

extern "C" arc::IDisplay *entryPoint()
{
	return lib;
}