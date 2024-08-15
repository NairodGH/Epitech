/*
** EPITECH PROJECT, 2022
** Buzz.hpp
** File description:
** Buzz
*/

#pragma once

#include "Toy.hpp"

class Buzz : public Toy {
    public:
        Buzz(const std::string &name, const std::string &filename = "buzz.txt");
        Buzz(const Buzz &cpy);
        virtual ~Buzz() = default;
        virtual void speak(std::string const statement);
        virtual bool speak_es(std::string const statement);
};