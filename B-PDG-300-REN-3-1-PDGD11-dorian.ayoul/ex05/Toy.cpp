/*
** EPITECH PROJECT, 2022
** Toy.cpp
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(ToyType type, std::string name, std::string ascii)
{
    _type = type;
    _name = name;
    _ascii = ascii;
}

Toy::Toy(const Toy &cpy)
{
    this->_type = cpy._type;
    this->_name = cpy._name;
    this->_ascii = cpy._ascii;
}

Toy::Toy()
{
    _type = BASIC_TOY;
    _name = "toy";
    _ascii.data = "";
}

Toy::ToyType Toy::getType() const
{
    return _type;
}

const std::string &Toy::getName() const
{
    return _name;
}

const std::string &Toy::getAscii() const
{
    return _ascii.data;
}

void Toy::setName(std::string name)
{
    _name = name;
}

void Toy::Error::setError(ErrorType error)
{
	type = error;
}

bool Toy::setAscii(std::string ascii)
{
    if (_ascii.getPictureFromFile(ascii))
        return true;
    else {
        _error.setError(Error::PICTURE);
        return false;
    }
}

Toy &Toy::operator=(const Toy &cpy)
{
    return *this;
}

void Toy::speak(const std::string statement)
{
	std::cout << _name << " \"" << statement << "\"" << std::endl;
}

Toy &Toy::operator<<(const std::string &ascii)
{
	_ascii.data = ascii;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Toy &toy)
{
	return os << toy.getName() << std::endl << toy.getAscii() << std::endl;
}

bool Toy::speak_es(const std::string statement)
{
	_error.setError(Error::SPEAK);
	return false;
}

Toy::Error::Error() : type(UNKNOWN)
{
}

std::string Toy::Error::what() const
{
    if (type == PICTURE)
        return "bad new illustration";
    else if (type == SPEAK)
        return "wrong mode";
    else
        return "";
}

std::string Toy::Error::where() const
{
    if (type == PICTURE)
        return "setAscii";
    else if (type == SPEAK)
        return "speak_es";
    else
        return "";
}

const Toy::Error &Toy::getLastError() const
{
	return _error;
}