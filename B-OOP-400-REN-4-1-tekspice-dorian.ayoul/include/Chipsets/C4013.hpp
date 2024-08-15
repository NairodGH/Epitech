/*
** EPITECH PROJECT, 2022
** C4013.hpp
** File description:
** C4013
*/

#pragma once

#include "Component.hpp"

class C4013 : public Component {
    public:
        C4013(const std::string &name);
        Tristate compute(size_t pin) override;
};