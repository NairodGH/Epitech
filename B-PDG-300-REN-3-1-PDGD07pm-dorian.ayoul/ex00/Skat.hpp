/*
** EPITECH PROJECT, 2022
** Skat.hpp
** File description:
** Skat
*/

#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

class Skat
{
    public:
        Skat(const std::string &name = "bob", int stimPaks = 15);
        ~Skat() = default;
        int &stimPaks(void);
        const std::string &name();
        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();
    private:
        std::string _name;
        int _stimPaks;

};