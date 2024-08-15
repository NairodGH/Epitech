/*
** EPITECH PROJECT, 2022
** Federation.cpp
** File description:
** Federation
*/

#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;
    this->_home = EARTH;
    this->_location = this->_home;
    this->_shield = 100;
    this->_photonTorpedo = torpedo;
    std::cout << "The ship USS " << name << " has been finished." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
    if (torpedo > 0)
        std::cout << "Weapons are set: " << torpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::Ship()
{
    this->_length = 289;
    this->_width = 132;
    this->_name = "Entreprise";
    this->_maxWarp = 6;
    this->_home = EARTH;
    this->_location = this->_home;
    this->_shield = 100;
    this->_photonTorpedo = 0;
    std::cout << "The ship USS Entreprise has been finished." << std::endl;
    std::cout << "It is 289 m in length and 132 m in width." << std::endl;
    std::cout << "It can go to Warp 6!" << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    std::cout << "USS " << _name << ": The core is " << (_core->checkReactor()->isStable() ? "stable" : "unstable")
    << " at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    _captain = captain;
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    _location = d;
    return warp <= _maxWarp && d != _location && _core->checkReactor()->isStable();
}

bool Federation::Starfleet::Ship::move(int warp)
{
    _location = _home;
    return warp <= _maxWarp && _home != _location && _core->checkReactor()->isStable();
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    _location = d;
    return _maxWarp <= _maxWarp && d != _location && _core->checkReactor()->isStable();
}

bool Federation::Starfleet::Ship::move()
{
    _location = _home;
    return _maxWarp <= _maxWarp && _home != _location && _core->checkReactor()->isStable();
}

int Federation::Starfleet::Ship::getShield()
{
    return _shield;
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return _photonTorpedo;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (_photonTorpedo == 0)
        std::cout << _name << ": No enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
    _photonTorpedo--;
    std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining ." << std::endl;
    target->setShield(target->getShield() - 50);
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (_photonTorpedo - torpedoes <= 0)
        std::cout << _name << ": No enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
    _photonTorpedo -= torpedoes;
    std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining ." << std::endl;
    target->setShield(target->getShield() - 50 * torpedoes);
}

Federation::Starfleet::Captain::Captain(std::string name)
{
    this->_name = name;
}

std::string Federation::Starfleet::Captain::getName()
{
    return _name;
}

int Federation::Starfleet::Captain::getAge()
{
    return _age;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    this->_name = name;
    std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = 1;
    this->_home = VULCAN;
    this->_location = this->_home;
    std::cout << "The independent ship " << name << " just finished its construction." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    std::cout << _name << ": The core is " << (_core->checkReactor()->isStable() ? "stable" : "unstable")
    << " at the time." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
    _location = d;
    return warp <= _maxWarp && d != _location && _core->checkReactor()->isStable();
}

bool Federation::Ship::move(int warp)
{
    _location = _home;
    return warp <= _maxWarp && _home != _location && _core->checkReactor()->isStable();
}

bool Federation::Ship::move(Destination d)
{
    _location = d;
    return _maxWarp <= _maxWarp && d != _location && _core->checkReactor()->isStable();
}

bool Federation::Ship::move()
{
    _location = _home;
    return _maxWarp <= _maxWarp && _home != _location && _core->checkReactor()->isStable();
}

WarpSystem::Core *Federation::Ship::getCore()
{
    return _core;
}