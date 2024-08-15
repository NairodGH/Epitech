/*
** EPITECH PROJECT, 2022
** Gate.cpp
** File description:
** Gate
*/

#include "Gate.hpp"

Tristate _and(Tristate a, Tristate b)
{
    if (a == UNDEFINED || b == UNDEFINED)
        return UNDEFINED;
    return (Tristate)(a && b);
}

Tristate _nand(Tristate a, Tristate b)
{
    if (a == UNDEFINED || b == UNDEFINED)
        return UNDEFINED;
    return (Tristate)!(a && b);
}

Tristate _or(Tristate a, Tristate b)
{
    if (a == UNDEFINED && b == UNDEFINED)
        return UNDEFINED;
    return a == UNDEFINED ? b : b == UNDEFINED ? a : (Tristate)(a || b);
}
Tristate _nor(Tristate a, Tristate b)
{
    if (a == UNDEFINED && b == UNDEFINED)
        return UNDEFINED;
    return (Tristate)!(a == UNDEFINED ? b : b == UNDEFINED ? a : (Tristate)(a || b));
}
Tristate _xor(Tristate a, Tristate b)
{
    if (a == UNDEFINED && b == UNDEFINED)
        return UNDEFINED;
    return a == UNDEFINED ? b : b == UNDEFINED ? a : (Tristate)(a != b);
}

Tristate _xnor(Tristate a, Tristate b)
{
    if (a == UNDEFINED && b == UNDEFINED)
        return UNDEFINED;
    return (Tristate)!(a == UNDEFINED ? b : b == UNDEFINED ? a : (Tristate)(a != b));
}

Tristate _not(Tristate a)
{
    if (a == UNDEFINED)
        return a;
    return (Tristate)!a;
}