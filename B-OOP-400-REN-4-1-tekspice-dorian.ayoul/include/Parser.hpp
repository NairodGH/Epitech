/*
** EPITECH PROJECT, 2022
** parser.hpp
** File description:
** parser
*/

#pragma once

#include "Component.hpp"
#include "Factory.hpp"
#include "Circuit.hpp"

class Parser {
    public:
        Parser() = default;
        virtual ~Parser() = default;
        void checkCommand(std::string command, Circuit &circuit);
        void setComponents(std::map<std::string, std::shared_ptr<IComponent>>);
        std::map<std::string, std::shared_ptr<IComponent>> getComponents() const;
        void parseFile(std::string path);
        void getWords(bool chipsets, bool links, std::string line);
        std::pair<std::string, std::shared_ptr<IComponent>> fillMap(std::vector<std::string> words);
        void findLinks(std::vector<std::string> words);
    private:
        std::map<std::string, std::shared_ptr<IComponent>> components;
        Factory factory;
};