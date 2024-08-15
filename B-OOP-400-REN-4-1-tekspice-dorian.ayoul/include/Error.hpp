/*
** EPITECH PROJECT, 2022
** Error.hpp
** File description:
** Error
*/

#pragma once

#include <exception>
#include <string>

class Error : public std::exception {
    public:
        Error(const std::string &error = "") throw();
        virtual ~Error();
        virtual const char *what() const throw();
    private:
        std::string message;
};