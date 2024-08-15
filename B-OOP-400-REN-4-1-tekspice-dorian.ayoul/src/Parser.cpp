/*
** EPITECH PROJECT, 2022
** parser.cpp
** File description:
** parser
*/

#include "Parser.hpp"
#include <algorithm>

void Parser::findLinks(std::vector<std::string> words)
{
    std::map<std::string, std::shared_ptr<IComponent>>::iterator it;
    std::map<std::string, std::shared_ptr<IComponent>>::iterator it2;
    std::string name = words[0].substr(0, words[0].find(":"));
    size_t val = (size_t)std::stoi(words[0].erase(0, words[0].find(":") + 1));
    std::string name2 = words[1].substr(0, words[1].find(":"));
    size_t val2 = (size_t)std::stoi(words[1].erase(0, words[1].find(":") + 1));

    it = this->components.find(name);
    if (it == this->components.end() && it->first != name)
        throw Error("Component " + name + " doesn't exists.");
    it2 = this->components.find(name2);
    if (it2 == this->components.end() && it2->first != name2)
        throw Error("Component " + name2 + " doesn't exists.");
    it->second->setLink(val, (*it2->second.get()), val2);
    it2->second->setLink(val2, (*it->second.get()), val);
}

std::pair<std::string, std::shared_ptr<IComponent>> Parser::fillMap(std::vector<std::string> words)
{
    std::pair<std::string, std::shared_ptr<IComponent>> mapelem;
    
    mapelem.first = words[1];
    mapelem.second = std::move(factory.createComponent(words[0]));
    words.clear();
    return (mapelem);
}

void Parser::getWords(bool chipsets, bool links, std::string line)
{
    std::istringstream split(line);
    std::string word;
    std::vector<std::string> save;

    while (std::getline(split, word, ' ')) {
        if (word == " " or word == "")
            continue;
        save.push_back(word);
    }
    if (save.size() != 2)
        throw Error(save[0]);
    if (chipsets) {
        if (this->components.find(save[1]) != this->components.end())
            throw Error("Some chipsets have the same name (" + save[1] + ")");
        this->components.insert(fillMap(save));
    }
    if (links)
        findLinks(save);
    save.clear();
}

void Parser::parseFile(std::string path)
{
    std::ifstream ifstream;
    std::string line;
    bool chipsets = false;
    bool links = true;

    ifstream.open(path);
    if (!ifstream.is_open())
        throw Error("Couldn't open file");
    while (std::getline(ifstream, line)) {
        if (line[0] == '#' || line[0] == ' ' || line[0] == '\t' || line[0] == '\n' || line[0] == '\0')
            continue;
        if (line == ".chipsets:") {
            chipsets = true;
            links = false;
        }
        else if (line == ".links:") {
            links = true;
            chipsets = false;
        }
        else {
            std::replace(line.begin(), line.end(), '\t', ' ');
            std::replace(line.begin(), line.end(), '\r', ' ');
            getWords(chipsets, links, line);
        }
    }
}

void displayComp(std::map<std::string, std::shared_ptr<IComponent>> &components)
{
    std::map<std::string, std::shared_ptr<IComponent>>::iterator it;

    for (it = components.begin(); it != components.end(); it++) {
        if (it->second->getPins().size() > 1)
            for (size_t i = 0; i != it->second->getPins().size(); i++) {
                if (it->second->getPins()[i]->getLink() != nullptr) {
                    std::cout << "ptr " << it->second->getPins()[i]->getLink()->getState() << std::endl;
                }
                else 
                    std::cout << it->second->getPins()[i]->getState() << std::endl;
            }
    }
}

void Parser::checkCommand(std::string command, Circuit &circuit)
{
    std::string input;
    std::string value;

    if (circuit.getDisplay() == "")
        circuit.createDisplay(this->components);
    if (command == "display")
        circuit.display();
    else if (command.find("=") != std::string::npos) {
        input = command.substr(0, command.find("="));
        if (components.find(input) == components.end() && components.end()->first != input)
            throw Error("Input " + input + " doesn't exist.");
        if (components[input].get()->getPins().size() != 1
            || components[input].get()->getPins().at(0)->getType() == Pin::O
            || components[input].get()->getPins().at(0)->getType() == Pin::U)
                throw Error(input + " isn't an input component.");
        value = command.substr(command.find("=") + 1, command.length());
        if (value == "0")
            circuit.input(input, FALSE, this->components);
        else if (value == "1")
            circuit.input(input, TRUE, this->components);
        else if (value == "U")
            circuit.input(input, UNDEFINED, this->components);
        else
            throw Error(value + " isn't a valid input state.");
    }
    else if (command == "simulate")
        circuit.simulate(this->components);
    else if (command == "loop")
        circuit.loop(this->components);
    else if (command == "dump")
        circuit.dump(this->components);
    else
        throw Error(command + " isn't a valid command.");
}