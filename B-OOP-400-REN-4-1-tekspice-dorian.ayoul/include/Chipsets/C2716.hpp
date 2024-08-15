/*
** EPITECH PROJECT, 2022
** C2716.hpp
** File description:
** C2716
*/

#pragma once

#include "Component.hpp"

class C2716 : public Component {
    public:
        C2716(const std::string &name);
        Tristate compute(size_t pin) override;
};