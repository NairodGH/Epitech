/*
** EPITECH PROJECT, 2022
** Error.cpp
** File description:
** Error
*/

#include "Error.hpp"

using namespace plz;

Error::Error(const std::string &error) throw()
{
    this->_message = error;
}

Error::~Error() throw()
{
}

const char *Error::what() const throw()
{
    return _message.c_str();
}