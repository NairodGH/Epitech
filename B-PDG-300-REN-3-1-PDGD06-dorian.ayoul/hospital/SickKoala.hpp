/*
** EPITECH PROJECT, 2022
** SickKoala.hpp
** File description:
** SickKoala
*/

#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

class SickKoala {
    public:
        SickKoala(std::string name);
        ~SickKoala();
        void poke(void);
        bool takeDrug(std::string drug);
        void overDrive(std::string kreog);
    private:
        std::string name;
};
