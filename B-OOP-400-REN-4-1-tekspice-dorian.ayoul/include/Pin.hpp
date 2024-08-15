/*
** EPITECH PROJECT, 2022
** Pin.hpp
** File description:
** Pin
*/

#pragma once

#include "IComponent.hpp"
#include "Gate.hpp"

class Pin {
    public:
        enum Type {
            I,
            O,
            U,
            T,
            F
        };
        Pin(size_t pin, Type type, Tristate state = Tristate::UNDEFINED);
        virtual ~Pin() = default;
        Type getType();
        void setType(Type type);
        Tristate getState();
        void setState(Tristate state);
        std::shared_ptr<Pin> &getLink();
        void setLink(std::shared_ptr<Pin> &pin);
        void setClock(Tristate clock);
        Tristate getClock();
    private:
        size_t _nb;
        Type _type;
        Tristate _state;
        Tristate _clock;
        std::shared_ptr<Pin> _link;
};