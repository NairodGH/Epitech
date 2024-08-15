/*
** EPITECH PROJECT, 2022
** Component.hpp
** File description:
** Component
*/

#pragma once

#include "Gate.hpp"
#include "Pin.hpp"
#include "Error.hpp"

class Component : public IComponent {
    public:
        Component() = default;
        virtual ~Component() = default;
        virtual void simulate(size_t tick);
        virtual Tristate compute(size_t pin);
        virtual void setLink(size_t pin, IComponent &other, size_t otherPin);
        virtual void dump() const;
        virtual std::string getName();
        virtual std::vector<std::shared_ptr<Pin>> &getPins();
    protected:
        std::string _name;
        std::vector<std::shared_ptr<Pin>> _pins;
};