/*
** EPITECH PROJECT, 2022
** calculator class
** File description:
** Calculator
*/

#ifndef CALCULATOR_HPP_
#define CALCULATOR_HPP_

#include "trade.hpp"
using std::string;

class Calculator {
    public:
        Calculator();
        ~Calculator() = default;
        void set_setting(string input);
        void set_candle(string input);
        Settings &get_settings();
        void act();
    private:
        std::vector<candle_t> candles;
        Settings settings;
        double emaShort;
        double emaMedium;
        double emaLong;
        double nvt;
        double lastNvt;
        double lastClose;
        size_t buyMultiplier;
        bool buy;
        bool sell;
        bool doBuy();
        bool doSell();
        double calcSma(size_t period);
        double calcEma(size_t period);
        double calcNvt(size_t period);
};

#endif /* !CALCULATOR_HPP_ */
