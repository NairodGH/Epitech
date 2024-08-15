/*
** EPITECH PROJECT, 2022
** C4011.hpp
** File description:
** C4011
*/

#pragma once

#include "Component.hpp"

class C4011 : public Component {
    public:
        C4011(const std::string &name);
        Tristate compute(size_t pin) override;
};