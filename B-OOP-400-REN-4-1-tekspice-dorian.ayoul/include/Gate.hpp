/*
** EPITECH PROJECT, 2022
** Gate.hpp
** File description:
** Gate
*/

#pragma once

#include "IComponent.hpp"

using namespace nts;

Tristate _and(Tristate a, Tristate b);
Tristate _nand(Tristate a, Tristate b);
Tristate _or(Tristate a, Tristate b);
Tristate _nor(Tristate a, Tristate b);
Tristate _xor(Tristate a, Tristate b);
Tristate _xnor(Tristate a, Tristate b);
Tristate _not(Tristate a);