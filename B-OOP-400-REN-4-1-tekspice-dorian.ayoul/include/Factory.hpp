/*
** EPITECH PROJECT, 2022
** Error.hpp
** File description:
** Error
*/

#pragma once

#include "Component.hpp"

class Factory {
    public:
        Factory();
        ~Factory() = default;
        std::unique_ptr<IComponent> createComponent(std::string const &type) const;
    private:
        std::unique_ptr<IComponent> create2716(const std::string &name) const;
        std::unique_ptr<IComponent> create4001(const std::string &name) const;
        std::unique_ptr<IComponent> create4008(const std::string &name) const;
        std::unique_ptr<IComponent> create4011(const std::string &name) const;
        std::unique_ptr<IComponent> create4013(const std::string &name) const;
        std::unique_ptr<IComponent> create4017(const std::string &name) const;
        std::unique_ptr<IComponent> create4030(const std::string &name) const;
        std::unique_ptr<IComponent> create4040(const std::string &name) const;
        std::unique_ptr<IComponent> create4069(const std::string &name) const;
        std::unique_ptr<IComponent> create4071(const std::string &name) const;
        std::unique_ptr<IComponent> create4081(const std::string &name) const;
        std::unique_ptr<IComponent> create4094(const std::string &name) const;
        std::unique_ptr<IComponent> create4512(const std::string &name) const;
        std::unique_ptr<IComponent> create4514(const std::string &name) const;
        std::unique_ptr<IComponent> create4801(const std::string &name) const;
        std::unique_ptr<IComponent> createLogger(const std::string &name) const;
        std::unique_ptr<IComponent> createInput(const std::string &name) const;
        std::unique_ptr<IComponent> createClock(const std::string &name) const;
        std::unique_ptr<IComponent> createTrue(const std::string &name) const;
        std::unique_ptr<IComponent> createFalse(const std::string &name) const;
        std::unique_ptr<IComponent> createOutput(const std::string &name) const;
        std::map<std::string, std::function<std::unique_ptr<IComponent>(Factory const &, std::string const &)>> _fact;
};