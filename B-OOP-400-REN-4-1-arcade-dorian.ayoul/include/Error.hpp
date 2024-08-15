/*
** EPITECH PROJECT, 2022
** Error.hpp
** File description:
** Error
*/

#pragma once

#include "includes.hpp"

/// All classes of the project are in the arc (arcade) namespace
namespace arc
{
    /// The error class safely checking for exceptions in the main
    class Error : public std::exception {
        public:
            /// Constructor that take the error message and throws the exception to be catched
            Error(const std::string &error = "") throw();
            virtual ~Error();
            /// Conventional error message getter to display it in a catch
            virtual const char *what() const throw();
        private:
            /// The error message provided
            std::string _message;
    };
}