/*
** EPITECH PROJECT, 2022
** Droid.hpp
** File description:
** Droid
*/

#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

class Droid {
    public:
        Droid(std::string id = "");
        Droid(const Droid &droid);
        ~Droid();
        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string *getStatus() const;
        void setId(std::string);
        void setEnergy(size_t);
        void setStatus(std::string *);
        Droid &operator=(const Droid &droid);
        bool operator==(const Droid &droid) const;
        bool operator!=(const Droid &droid) const;
        Droid &operator<<(size_t &);
    private:
        std::string _id;
        size_t _energy;
        const size_t _attack = 25;
        const size_t _toughness = 15;
        std::string *_status;
};

std::ostream &operator<<(std::ostream &os, const Droid & droid);