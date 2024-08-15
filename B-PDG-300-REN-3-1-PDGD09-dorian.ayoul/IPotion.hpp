/*
** EPITECH PROJECT, 2022
** iPotion.hpp
** File description:
** iPotion
*/

#pragma once

class IPotion
{
    public:
        virtual ~IPotion() = default;
        int getPower() const
        {
            return _power;
        }
        int getHp() const
        {
            return _hp;
        }
    protected:
        int _power;
        int _hp;
};