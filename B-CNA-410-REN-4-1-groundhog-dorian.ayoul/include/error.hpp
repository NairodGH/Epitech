/*
** EPITECH PROJECT, 2022
** error.hpp
** File description:
** error
*/

#pragma once

#include <exception>
#include <string>

class error : public std::exception {
    public:
        error(const std::string &error = "") throw();
        virtual ~error() throw();
        virtual const char *what() const throw();
    private:
        std::string message;
};