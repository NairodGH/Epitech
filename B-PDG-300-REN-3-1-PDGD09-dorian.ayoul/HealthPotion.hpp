/*
** EPITECH PROJECT, 2022
** HealthPotion.hpp
** File description:
** HealthPotion
*/

#pragma once

#include "IPotion.hpp"

class HealthPotion : virtual public IPotion
{
    public:
        HealthPotion();
        ~HealthPotion() = default;
};