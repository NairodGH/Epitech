/*
** EPITECH PROJECT, 2022
** C4512.hpp
** File description:
** C4512
*/

#pragma once

#include "Component.hpp"

class C4512 : public Component {
    public:
        C4512(const std::string &name);
        Tristate compute(size_t pin) override;
};