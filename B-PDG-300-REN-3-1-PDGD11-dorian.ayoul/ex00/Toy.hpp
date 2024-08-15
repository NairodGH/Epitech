/*
** EPITECH PROJECT, 2022
** Toy.hpp
** File description:
** Toy
*/

#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "Picture.hpp"

class Toy
{
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN
        };
        Toy(ToyType type, std::string name, std::string ascii);
        Toy();
        virtual ~Toy() = default;
        ToyType getType() const;
        std::string getName() const;
        std::string getAscii() const;
        void setName(std::string name);
        bool setAscii(std::string ascii);
    private:
        ToyType _type;
        std::string _name;
        Picture _ascii;
};