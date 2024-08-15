/*
** EPITECH PROJECT, 2022
** C4514.hpp
** File description:
** C4514
*/

#pragma once

#include "Component.hpp"

class C4514 : public Component {
    public:
        C4514(const std::string &name);
        Tristate compute(size_t pin) override;
};