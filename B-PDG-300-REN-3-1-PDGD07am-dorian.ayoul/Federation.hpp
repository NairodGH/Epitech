/*
** EPITECH PROJECT, 2022
** Federation.hpp
** File description:
** Federation
*/

#pragma once

#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Borg
{
    class Ship;
}

#include "Borg.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Captain {
            public:
                Captain(std::string name);
                ~Captain() = default;
                std::string getName();
                int getAge();
                void setAge(int age);
            private:
                std::string _name;
                int _age;
        };
        class Ship {
            public:
                Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0);
                Ship();
                ~Ship() = default;
                void setupCore(WarpSystem::Core *core);
                void checkCore(void);
                void promote(Captain *captain);
                bool move(int warp, Destination d);
                bool move(int warp);
                bool move(Destination d);
                bool move();
                int getShield();
                void setShield(int shield);
                int getTorpedo();
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *target);
                void fire(int torpedoes, Borg::Ship *target);
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core;
                Captain *_captain;
                Destination _location;
                Destination _home;
                int _shield;
                int _photonTorpedo;
        };
        class Ensign {
            public:
                Ensign(std::string name);
                ~Ensign() = default;
            private:
                std::string _name;
        };
    }
    class Ship {
        public:
            Ship(int length, int width, std::string name);
            ~Ship() = default;
            void setupCore(WarpSystem::Core *core);
            void checkCore(void);
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            WarpSystem::Core *getCore();
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home;
    };
}
