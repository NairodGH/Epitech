/*
** EPITECH PROJECT, 2022
** C4094.hpp
** File description:
** C4094
*/

#pragma once

#include "Component.hpp"

class C4094 : public Component {
    public:
        C4094(const std::string &name);
        Tristate compute(size_t pin) override;
};