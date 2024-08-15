/*
** EPITECH PROJECT, 2022
** entryPoint.cpp
** File description:
** entryPoint
*/

#include "Nibbler.hpp"

arc::IGame *lib = nullptr;

__attribute__((constructor))
void loadLib()
{
	lib = new arc::Nibbler;
}

__attribute__((destructor))
void unloadLib()
{
	delete lib;
}

extern "C" arc::IGame *entryPoint()
{
	return lib;
}