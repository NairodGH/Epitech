/*
** EPITECH PROJECT, 2022
** SickKoala.cpp
** File description:
** SickKoala
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name)
{
    this->name = name;
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke(void)
{
    std::cout << "Mr." << name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string drug)
{
    if (drug == "Mars")
        std::cout << "Mr." << name << ": Mars, and it kreogs!" << std::endl;
    else if (drug == "Kinder")
        std::cout << "Mr." << name << ": There is a toy inside!" << std::endl;
    else
        std::cout << "Mr." << name << ": Goerkreog!" << std::endl;
    return (drug == "Mars" || drug == "Kinder") ? true : false;
}

void SickKoala::overDrive(std::string kreog)
{
    size_t pos = 0;

    while ((pos = kreog.find("Kreog!")) != std::string::npos)
        kreog.replace(pos, 6, "1337!");
    std::cout << "Mr." << name << ": " << kreog << std::endl;
}
