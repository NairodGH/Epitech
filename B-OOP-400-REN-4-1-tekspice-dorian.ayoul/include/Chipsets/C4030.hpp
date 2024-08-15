/*
** EPITECH PROJECT, 2022
** C4030.hpp
** File description:
** C4030
*/

#pragma once

#include "Component.hpp"

class C4030 : public Component {
    public:
        C4030(const std::string &name);
        Tristate compute(size_t pin) override;
};