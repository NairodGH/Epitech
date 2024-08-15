/*
** EPITECH PROJECT, 2022
** main.cpp
** File description:
** main.cpp
*/

#include "Protocol.hpp"
#include "AI.hpp"

int main()
{
    Protocol protocol;
    AI ai;
    std::srand(std::time(nullptr));

    for (std::string input; std::getline(std::cin, input);) {
        protocol.getCommand(input);
        if (protocol.getTurn()) {
            ai.play(protocol.getBoard());
            protocol.setTurn(false);
        }
    }
    return 0;
}