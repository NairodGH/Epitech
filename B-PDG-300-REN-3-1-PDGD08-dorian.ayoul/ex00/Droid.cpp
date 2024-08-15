/*
** EPITECH PROJECT, 2022
** Droid.cpp
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string id)
{
    this->_id = id;
    this->_energy = 50;
    this->_status = new std::string("Standing by");
    std::cout << "Droid '" << this->_id << "' " << "Activated" << std::endl;
}

Droid::Droid(const Droid &droid) : _attack(droid._attack), _toughness(droid._toughness)
{
    this->_id = droid._id;
    this->_energy = droid._energy;
    if (droid._status)
        this->_status = new std::string(*droid._status);
    else
        this->_status = new std::string("Standing by");
    std::cout << "Droid '" << this->_id << "' " << "Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    if (this->_status)
        delete this->_status;
    std::cout << "Droid '" << this->_id << "' " << "Destroyed" << std::endl;
}

std::string Droid::getId() const
{
    return(this->_id);
}

size_t Droid::getEnergy() const
{
    return(this->_energy);
}

size_t Droid::getAttack() const
{
    return(this->_attack);
}

size_t Droid::getToughness() const
{
    return(this->_toughness);
}

std::string *Droid::getStatus() const
{
    return(this->_status);
}

void Droid::setId(std::string id)
{
    this->_id = id;
}

void Droid::setEnergy(size_t energy)
{
    this->_energy = energy;
}

void Droid::setStatus(std::string *status)
{
    this->_status = status;
}

Droid &Droid::operator=(const Droid &droid)
{
    this->_id = droid._id;
    this->_energy = droid._energy;
    if (this->_status)
        delete this->_status;
    this->_status = new std::string(*(droid._status));
    return(*this);
}

bool Droid::operator==(const Droid &droid) const
{
    return this->_id == droid._id && this->_energy == droid._energy && this->_attack == droid._attack &&
    this->_toughness == droid._toughness && *this->_status == *droid._status;
}

bool Droid::operator!=(const Droid &droid) const
{
    return !(*this == droid);
}

Droid &Droid::operator<<(size_t &energy)
{
    int min = 100 - this->_energy > energy ? energy : 100 - this->_energy;
    if (this->_energy < 100) {
        this->_energy += min;
        energy -= min;
    }
    return(*this);
}

std::ostream &operator<<(std::ostream &os, const Droid &droid) {
    if (droid.getEnergy() > 100)
        return(os << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", 100");
    else
        return(os << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy());
}