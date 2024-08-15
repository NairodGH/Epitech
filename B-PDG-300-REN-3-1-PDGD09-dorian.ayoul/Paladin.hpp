/*
** EPITECH PROJECT, 2022
** Paladin.hpp
** File description:
** Paladin
*/

#pragma once

#include "Priest.hpp"
#include "Knight.hpp"

class Paladin : public Knight, public Priest
{
    public:
        Paladin(const std::string &name, int power);
        ~Paladin();
        int attack();
        int special();
        void rest();
};