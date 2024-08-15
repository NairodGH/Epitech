/*
** EPITECH PROJECT, 2022
** Error.cpp
** File description:
** error
*/

#include "Error.hpp"

arc::Error::Error(const std::string &error) throw()
{
    this->_message = error;
}

arc::Error::~Error() throw()
{
}

const char *arc::Error::what() const throw()
{
    return _message.c_str();
}