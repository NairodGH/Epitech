/*
** EPITECH PROJECT, 2022
** KoalaBot.cpp
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"
#include "Parts.hpp"

KoalaBot::KoalaBot(std::string _serial) 
{
    this->_serial = _serial;
}

void KoalaBot::setParts(Arms &arms)
{
    _arms = arms;
}

void KoalaBot::setParts(Legs &legs)
{
    _legs = legs;
}

void KoalaBot::setParts(Head &head)
{
    _head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    Arms tmp = _arms;

    _arms = arms;
    arms = tmp;
}

void KoalaBot::swapParts(Legs &legs)
{
    Legs tmp = _legs;

    _legs = legs;
    legs = tmp;
}

void KoalaBot::swapParts(Head &head)
{
    Head tmp = _head;

    _head = head;
    head = tmp;
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    std::cout << "\t";
    _arms.informations();
    std::cout << "\t";
    _legs.informations();
    std::cout << "\t";
    _head.informations();
}

bool KoalaBot::status() const
{
    return _arms.isFunctional() && _legs.isFunctional() && _head.isFunctional();
}