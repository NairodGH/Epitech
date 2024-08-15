/*
** EPITECH PROJECT, 2022
** entryPoint.cpp
** File description:
** entryPoint
*/

#include "Pacman.hpp"

arc::IGame *lib = nullptr;

__attribute__((constructor))
void loadLib()
{
	lib = new arc::Pacman;
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