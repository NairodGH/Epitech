/*
** EPITECH PROJECT, 2022
** Settings.hpp
** File description:
** Settings
*/

#pragma once

class Settings
{
    public:
        Settings();
        ~Settings() = default;
        int getTimebank();
        void setTimebank(int timebank);
        int getTimePerMove();
        void setTimePerMove(int timePerMove);
        int getCandleInterval();
        void setCandleInterval(int candleInterval);
        int getCandlesTotal();
        void setCandlesTotal(int candlesTotal);
        int getCandlesGiven();
        void setCandlesGiven(int candlesGiven);
        double getTransactionFeePercent();
        void setTransactionFeePercent(double transactionFeePercent);
        double getBTC();
        void setBTC(double BTC);
        double getUSDT();
        void setUSDT(double USDT);
        void subBTC(double BTC);
        void subUSDT(double USDT);
        void addBTC(double BTC);
        void addUSDT(double USDT);
    private:
        int _timebank;
        int _timePerMove;
        int _candleInterval;
        int _candlesTotal;
        int _candlesGiven;
        double _transactionFeePercent;
        double _BTC;
        double _USDT;
};