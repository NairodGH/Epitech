/*
** EPITECH PROJECT, 2022
** entryPoint.cpp
** File description:
** entryPoint
*/

#include "ncurses.hpp"

arc::IDisplay *lib = nullptr;

__attribute__((constructor))
void loadLib()
{
	lib = new arc::ncurses;
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