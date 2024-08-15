/*
** EPITECH PROJECT, 2022
** LittleHand.hpp
** File description:
** LittleHand
*/

#pragma once

#include "Banana.hpp"
#include "Lemon.hpp"
#include "Lime.hpp"
#include "FruitBox.hpp"

class LittleHand
{
    public:
        LittleHand() = default;
        virtual ~LittleHand() = default;
        static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
};