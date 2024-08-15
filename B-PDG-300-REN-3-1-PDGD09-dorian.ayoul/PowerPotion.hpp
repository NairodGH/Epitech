/*
** EPITECH PROJECT, 2022
** PowerPotion.hpp
** File description:
** PowerPotion
*/

#pragma once

#include "IPotion.hpp"

class PowerPotion : virtual public IPotion
{
    public:
        PowerPotion();
        ~PowerPotion() = default;
};