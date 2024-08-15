/*
** EPITECH PROJECT, 2022
** error.cpp
** File description:
** error
*/

#include "error.hpp"

error::error(const std::string &error) throw()
{
    this->message = error;
}

error::~error() throw()
{
}

const char *error::what() const throw()
{
    return message.c_str();
}