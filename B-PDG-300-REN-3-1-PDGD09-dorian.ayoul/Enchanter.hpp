/*
** EPITECH PROJECT, 2022
** Enchanter.hpp
** File description:
** Enchanter
*/

#pragma once

#include "Peasant.hpp"

class Enchanter : public virtual Peasant
{
    public:
        Enchanter(const std::string &name, int power);
        ~Enchanter();
        int attack();
        int special();
        void rest();
};