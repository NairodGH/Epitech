/*
** EPITECH PROJECT, 2022
** Borg.hpp
** File description:
** Borg
*/

#pragma once

#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Ship;
    }
    class Ship;
}

#include "Federation.hpp"

namespace Borg
{
    class Ship {
        public:
            Ship(int weaponFrequency = 20 , short repair = 3);
            ~Ship() = default;
            void setupCore(WarpSystem::Core *core);
            void checkCore(void);
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            int getShield();
            void setShield(int shield);
            int getWeaponFrequency();
            void setWeaponFrequency(int frequency);
            short getRepair();
            void setRepair(short repair);
            void fire(Federation::Starfleet::Ship *target);
            void fire(Federation::Ship *target);
            void repair();
        private:
            int _side;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home;
            int _shield ;
            int _weaponFrequency ;
            short _repair ;
    };
}
