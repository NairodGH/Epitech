/*
** EPITECH PROJECT, 2022
** KoalaNurse.hpp
** File description:
** KoalaNurse
*/

#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "SickKoala.hpp"

class KoalaNurse {
    public:
        KoalaNurse(int ID);
        ~KoalaNurse();
        void giveDrug(std::string drug, SickKoala *patient);
        std::string readReport(std::string path);
        void timeCheck(void);
    private:
        int ID;
        bool isWorking;
};
