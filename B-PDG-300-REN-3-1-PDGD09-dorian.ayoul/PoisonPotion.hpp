/*
** EPITECH PROJECT, 2022
** PoisonPotion.hpp
** File description:
** PoisonPotion
*/

#pragma once

#include "IPotion.hpp"

class PoisonPotion : virtual public IPotion
{
    public:
        PoisonPotion();
        ~PoisonPotion() = default;
};