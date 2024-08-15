/*
** EPITECH PROJECT, 2022
** C4071.hpp
** File description:
** C4071
*/

#pragma once

#include "Component.hpp"

class C4071 : public Component {
    public:
        C4071(const std::string &name);
        Tristate compute(size_t pin) override;
};