/*
** EPITECH PROJECT, 2022
** C4001.hpp
** File description:
** C4001
*/

#pragma once

#include "Component.hpp"

class C4001 : public Component {
    public:
        C4001(const std::string &name);
        Tristate compute(size_t pin) override;
};