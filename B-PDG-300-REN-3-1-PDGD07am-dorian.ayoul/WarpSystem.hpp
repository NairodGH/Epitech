/*
** EPITECH PROJECT, 2022
** WarpSystem.hpp
** File description:
** WarpSystem
*/

#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

namespace WarpSystem
{
    class QuantumReactor {
        public:
            QuantumReactor();
            ~QuantumReactor() = default;
            bool isStable();
            void setStability(bool stability);
        private:
            bool _stability;
    };
    class Core {
        public:
            Core(QuantumReactor *_coreReactor);
            ~Core() = default;
            QuantumReactor *checkReactor();
        private:
            QuantumReactor *_coreReactor;
    };
}