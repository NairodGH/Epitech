/*
** EPITECH PROJECT, 2022
** Parts.hpp
** File description:
** Parts
*/

#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

class Arms
{
    public:
        Arms(const std::string &serial = "A-01", bool functional = true);
        ~Arms() = default;
        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
    private:
        std::string _serial;
        bool _functional;
};

class Legs
{
    public:
        Legs(const std::string &serial = "L-01", bool functional = true);
        ~Legs() = default;
        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
    private:
        std::string _serial;
        bool _functional;
};

class Head
{
    public:
        Head(const std::string &serial = "H-01", bool functional = true);
        ~Head() = default;
        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
    private:
        std::string _serial;
        bool _functional;
};