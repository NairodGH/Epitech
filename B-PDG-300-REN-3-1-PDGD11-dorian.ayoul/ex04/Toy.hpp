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
        Toy(ToyType type, std::string name, std::string ascii);
        Toy(const Toy &cpy);
        Toy();
        virtual ~Toy() = default;
        ToyType getType() const;
        std::string getName() const;
        std::string getAscii() const;
        void setName(std::string name);
        bool setAscii(std::string ascii);
        Toy &operator=(const Toy &cpy);
        virtual void speak(std::string const statement);
        Toy &operator<<(const std::string &ascii);
    protected:
        ToyType _type;
        std::string _name;
        Picture _ascii;
};

std::ostream &operator<<(std::ostream &os, const Toy &toy);