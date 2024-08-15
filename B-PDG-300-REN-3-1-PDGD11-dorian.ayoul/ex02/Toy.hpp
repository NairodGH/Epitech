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
            ALIEN,
            BUZZ,
            WOODY
        };
        Toy(ToyType type, const std::string &name, const std::string &ascii);
        Toy(const Toy &cpy);
        Toy();
        virtual ~Toy() = default;
        ToyType getType() const;
        const std::string &getName() const;
        const std::string &getAscii() const;
        void setName(const std::string &name);
        bool setAscii(const std::string &ascii);
        Toy &operator=(const Toy &cpy);
    private:
        ToyType _type;
        std::string _name;
        Picture _ascii;
};