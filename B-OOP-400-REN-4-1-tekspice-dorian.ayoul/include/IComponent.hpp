/*
** EPITECH PROJECT, 2022
** IComponent.hpp
** File description:
** IComponent
*/

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <memory>
#include <sstream>
#include <csignal>
#include <functional>
class Pin;

namespace nts
{
    enum Tristate
    {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    class IComponent
    {
        public:
            virtual ~IComponent() = default;
            virtual void simulate(size_t tick) = 0;
            virtual Tristate compute(size_t pin) = 0;
            virtual void setLink(size_t pin, IComponent &other, std::
            size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual std::vector<std::shared_ptr<Pin>> &getPins() = 0;
    };
}