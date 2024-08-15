/*
** EPITECH PROJECT, 2022
** Banana.hpp
** File description:
** Banana
*/

#include "Fruit.hpp"

#pragma once

class Banana : virtual public Fruit
{
    public:
        Banana();
        virtual ~Banana() = default;
};