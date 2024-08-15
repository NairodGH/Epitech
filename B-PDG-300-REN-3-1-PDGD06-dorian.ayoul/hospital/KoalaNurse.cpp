/*
** EPITECH PROJECT, 2022
** KoalaNurse.cpp
** File description:
** KoalaNurse
*/

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int ID)
{
    this->ID = ID;
    this->isWorking = false;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << ID << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
    patient->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string path)
{
    std::ifstream file(path);
    std::string drugName;

    if (path.find(".report") == std::string::npos || path == ".report")
        return "";
    if (file.is_open()) {
        getline(file, drugName);
        if (drugName != "Mars" && drugName != "Kinder")
            return "";
        std::cout << "Nurse " << std::to_string(ID) << ": Kreog! Mr." << path.substr(0, path.find(".report"))
             << " needs a " << drugName << "!" << std::endl;
        return drugName;
    }
    else
        return "";
}

void KoalaNurse::timeCheck(void)
{
    if (isWorking)
        std::cout << "Nurse " << ID << ": Time to go home to my eucalyptus forest!" << std::endl;
    else
        std::cout << "Nurse " << ID << ": Time to get to work!" << std::endl;
    isWorking = !isWorking;
}
