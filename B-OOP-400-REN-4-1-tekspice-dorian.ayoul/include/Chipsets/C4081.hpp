/*
** EPITECH PROJECT, 2022
** C4081.hpp
** File description:
** C4081
*/

#pragma once

#include "Component.hpp"

class C4081 : public Component {
    public:
        C4081(const std::string &name);
        Tristate compute(size_t pin) override;
};