/*
** EPITECH PROJECT, 2022
** C4040.hpp
** File description:
** C4040
*/

#pragma once

#include "Component.hpp"

class C4040 : public Component {
    public:
        C4040(const std::string &name);
        Tristate compute(size_t pin) override;
};