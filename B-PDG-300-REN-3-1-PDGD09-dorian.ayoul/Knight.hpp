/*
** EPITECH PROJECT, 2022
** Knight.hpp
** File description:
** Knight
*/

#pragma once

#include "Peasant.hpp"

class Knight : public virtual Peasant
{
    public:
        Knight(const std::string &name, int power);
        ~Knight();
        int attack();
        int special();
        void rest();
};