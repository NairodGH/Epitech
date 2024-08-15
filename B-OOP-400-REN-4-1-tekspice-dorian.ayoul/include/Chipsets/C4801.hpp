/*
** EPITECH PROJECT, 2022
** C4801.hpp
** File description:
** C4801
*/

#pragma once

#include "Component.hpp"

class C4801 : public Component {
    public:
        C4801(const std::string &name);
        Tristate compute(size_t pin) override;
};