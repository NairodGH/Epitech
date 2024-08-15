/*
** EPITECH PROJECT, 2022
** Lemon.hpp
** File description:
** Lemon
*/

#include "Fruit.hpp"

#pragma once

class Lemon : virtual public Fruit
{
    public:
        Lemon();
        virtual ~Lemon() = default;
};