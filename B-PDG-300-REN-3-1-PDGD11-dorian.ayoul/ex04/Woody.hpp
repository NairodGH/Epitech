/*
** EPITECH PROJECT, 2022
** Woody.hpp
** File description:
** Woody
*/

#pragma once

#include "Toy.hpp"

class Woody : public Toy {
    public:
        Woody(const std::string &name, const std::string &filename = "woody.txt");
        Woody(const Woody &cpy);
        virtual ~Woody() = default;
        virtual void speak(std::string const statement);
};