/*
** EPITECH PROJECT, 2022
** C4069.hpp
** File description:
** C4069
*/

#pragma once

#include "Component.hpp"

class C4069 : public Component {
    public:
        C4069(const std::string &name);
        Tristate compute(size_t pin) override;
};