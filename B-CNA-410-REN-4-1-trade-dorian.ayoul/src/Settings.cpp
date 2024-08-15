/*
** EPITECH PROJECT, 2022
** Settings.cpp
** File description:
** Settings
*/

#include "Settings.hpp"

Settings::Settings() /*: tes valeurs par défaut*/
{
    _USDT = 0;
    _BTC = 0;
}

int Settings::getTimebank()
{
    return _timebank;
}

void Settings::setTimebank(int timebank)
{
    _timebank = timebank;
}

int Settings::getTimePerMove()
{
    return _timePerMove;
}

void Settings::setTimePerMove(int timePerMove)
{
    _timePerMove = timePerMove;
}

int Settings::getCandleInterval()
{
    return _candleInterval;
}

void Settings::setCandleInterval(int candleInterval)
{
    _candleInterval = candleInterval;
}

int Settings::getCandlesTotal()
{
    return _candlesTotal;
}

void Settings::setCandlesTotal(int candlesTotal)
{
    _candlesTotal = candlesTotal;
}

int Settings::getCandlesGiven()
{
    return _candlesGiven;
}

void Settings::setCandlesGiven(int candlesGiven)
{
    _candlesGiven = candlesGiven;
}

double Settings::getTransactionFeePercent()
{
    return _transactionFeePercent;
}

void Settings::setTransactionFeePercent(double transactionFeePercent)
{
    _transactionFeePercent = transactionFeePercent;
}

double Settings::getBTC()
{
    return _BTC;
}

void Settings::setBTC(double BTC)
{
    _BTC = BTC;
}

double Settings::getUSDT()
{
    return _USDT;
}

void Settings::setUSDT(double USDT)
{
    _USDT = USDT;
}

void Settings::subBTC(double BTC)
{
    _BTC -= BTC;
}

void Settings::subUSDT(double USDT)
{
    _USDT -= USDT;
}

void Settings::addBTC(double BTC)
{
    _BTC += BTC;
}

void Settings::addUSDT(double USDT)
{
    _USDT += USDT;
}