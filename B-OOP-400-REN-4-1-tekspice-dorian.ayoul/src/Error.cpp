/*
** EPITECH PROJECT, 2022
** Error.cpp
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(const std::string &error) throw()
{
    this->message = error;
}

Error::~Error() throw()
{
}

const char *Error::what() const throw()
{
    return message.c_str();
}