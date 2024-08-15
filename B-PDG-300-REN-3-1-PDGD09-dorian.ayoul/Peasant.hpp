/*
** EPITECH PROJECT, 2022
** Peasant.hpp
** File description:
** Peasant
*/

#pragma once

#include "ICharacter.hpp"

class Peasant : public virtual ICharacter
{
    public:
        Peasant(const std::string &name, int power);
        ~Peasant();
        const std::string &getName() const;
        int getPower() const;
        int getHp() const;
        virtual int attack();
        virtual int special();
        virtual void rest();
        void damage(int damage);
        void drink(const HealthPotion& potion);
        void drink(const PowerPotion& potion);
        void drink(const PoisonPotion& potion);
        void drink(const IPotion& potion);
    protected:
        std::string _name;
        int _power;
        int _hp;
};
