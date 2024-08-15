/*
** EPITECH PROJECT, 2022
** C4008.hpp
** File description:
** C4008
*/

#pragma once

#include "Component.hpp"

class C4008 : public Component {
    public:
        C4008(const std::string &name);
        Tristate compute(size_t pin) override;
};