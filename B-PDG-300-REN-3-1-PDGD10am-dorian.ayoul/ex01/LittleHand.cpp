/*
** EPITECH PROJECT, 2022
** LittleHand.cpp
** File description:
** LittleHand
*/

#include "LittleHand.hpp"

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    FruitNode *tmp = unsorted.head();
    Fruit *tmp2;
    Fruit *tmp3;
    size_t size = unsorted.nbFruits();

    for (size_t i = 0; i < size; i++) {
        tmp2 = tmp->_data;
        if (dynamic_cast<Lemon *>(tmp2)) {
            if (!lemons.putFruit(tmp3 = unsorted.pickFruit()))
                unsorted.putFruit(tmp3);
        }
        else if (dynamic_cast<Banana *>(tmp2)) {
            if (!bananas.putFruit(tmp3 = unsorted.pickFruit()))
                unsorted.putFruit(tmp3);
        }
        else if (dynamic_cast<Lime *>(tmp2)) {
            if (!limes.putFruit(tmp3 = unsorted.pickFruit()))
                unsorted.putFruit(tmp3);
        }
        tmp = tmp->_next;
    }
}