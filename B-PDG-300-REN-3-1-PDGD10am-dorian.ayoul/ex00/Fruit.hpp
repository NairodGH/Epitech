/*
** EPITECH PROJECT, 2022
** Fruit.hpp
** File description:
** Fruit
*/

#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

class Fruit
{
    public:
        Fruit(int vitamins, const std::string name);
        virtual ~Fruit() = default;
        int getVitamins() const;
        std::string getName() const;
    protected:
        int _vitamins;
        std::string _name;
};