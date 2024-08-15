/*
** EPITECH PROJECT, 2022
** FruitBox.hpp
** File description:
** FruitBox
*/

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox
{
    public:
        FruitBox(int size);
        virtual ~FruitBox() = default;
        int nbFruits() const;
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head() const;
    protected:
        FruitNode *_node;
        int _size;
};