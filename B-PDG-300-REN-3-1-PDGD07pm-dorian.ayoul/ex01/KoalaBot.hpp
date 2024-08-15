/*
** EPITECH PROJECT, 2022
** KoalaBot.hpp
** File description:
** KoalaBot
*/

#pragma once

#include "Parts.hpp"

class KoalaBot
{
    public:
        KoalaBot(const std::string _serial = "Bob-01");
        ~KoalaBot() = default;
        void setParts(Arms &arms);
        void setParts(Legs &legs);
        void setParts(Head &head);
        void swapParts(Arms &arms);
        void swapParts(Legs &legs);
        void swapParts(Head &head);
        void informations() const;
        bool status() const;
    private:
        Arms _arms;
        Legs _legs;
        Head _head;
        std::string _serial;
};