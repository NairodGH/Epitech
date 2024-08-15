/*
** EPITECH PROJECT, 2022
** C4017.hpp
** File description:
** C4017
*/

#pragma once

#include "Component.hpp"

class C4017 : public Component {
    public:
        C4017(const std::string &name);
        Tristate compute(size_t pin) override;
};