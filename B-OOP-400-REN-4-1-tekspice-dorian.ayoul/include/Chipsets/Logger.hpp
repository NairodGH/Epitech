/*
** EPITECH PROJECT, 2022
** Logger.hpp
** File description:
** Logger
*/

#pragma once

#include "Component.hpp"

class Logger : public Component {
    public:
        Logger(const std::string &name);
        Tristate compute(size_t pin) override;
};