/*
** EPITECH PROJECT, 2022
** entryPoint.cpp
** File description:
** entryPoint
*/

#include "SDL2.hpp"

arc::IDisplay *lib = nullptr;

__attribute__((constructor))
void loadLib()
{
	lib = new arc::SDL2;
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