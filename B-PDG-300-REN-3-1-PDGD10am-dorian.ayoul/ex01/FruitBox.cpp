/*
** EPITECH PROJECT, 2022
** FruitBox.cpp
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size)
{
    this->_node = nullptr;
    this->_size = size;
}

int FruitBox::nbFruits() const
{
    FruitNode *tmp = _node;
    int count = 0;

    while (tmp != nullptr) {
        count++;
        tmp = tmp->_next;
    }
    return count;
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode *tmp = _node;
    FruitNode *tmp2;
    size_t i = 1;

    if (i >= _size)
        return false;
    if (_node == nullptr) {
        _node = new FruitNode;
        _node->_data = f;
        _node->_next = nullptr;
        return true;
    }
    for (; tmp->_next != nullptr; i++) {
        if (tmp->_data == f || i >= _size)
            return false;
        tmp = tmp->_next;
    }
    if (tmp->_data == f || i >= _size)
        return false;
    tmp2 = new FruitNode;
    tmp2->_data = f;
    tmp2->_next = nullptr;
    tmp->_next = tmp2;
    return true;
}

Fruit *FruitBox::pickFruit()
{
    FruitNode *tmp = _node;
    Fruit *tmp2;

    if (_node == nullptr)
        return nullptr;
    tmp2 = _node->_data;
    _node = _node->_next;
    delete tmp;
    return tmp2;
}

FruitNode *FruitBox::head() const
{
    if (_node == nullptr)
        return nullptr;
    return _node;
}