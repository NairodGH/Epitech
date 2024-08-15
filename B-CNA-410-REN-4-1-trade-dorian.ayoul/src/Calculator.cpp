/*
** EPITECH PROJECT, 2022
** Calculator funcs
** File description:
** Calculator
*/

#include "Calculator.hpp"

Calculator::Calculator()
{
    lastClose = 0;
    lastNvt = 0;
}

void Calculator::set_setting(std::string input)
{
    if (input.find("timebank") != std::string::npos)
        settings.setTimebank(std::stoi(input.substr(input.find_last_of(' ') + 1)));
    if (input.find("time_per_move") != std::string::npos)
        settings.setTimePerMove(std::stoi(input.substr(input.find_last_of(' ') + 1)));
    if (input.find("initial_stack") != std::string::npos)
        settings.setUSDT(std::stoi(input.substr(input.find_last_of(' ') + 1)));
    if (input.find("candle_interval") != std::string::npos)
        settings.setCandleInterval(std::stoi(input.substr(input.find_last_of(' ') + 1)));
    if (input.find("candles_total") != std::string::npos)
        settings.setCandlesTotal(std::stoi(input.substr(input.find_last_of(' ') + 1)));
    if (input.find("candles_given") != std::string::npos)
        settings.setCandlesGiven(std::stoi(input.substr(input.find_last_of(' ') + 1)));
    if (input.find("transaction_fee_percent") != std::string::npos)
        settings.setTransactionFeePercent(std::stof(input.substr(input.find_last_of(' ') + 1)));
}

void Calculator::set_candle(std::string input)
{
    candle_t candle;
    std::strtok(const_cast<char *>(input.c_str()), ",");

    std::strtok(NULL, ",");
    candle.high = std::atof(std::strtok(NULL, ","));
    candle.low = std::atof(std::strtok(NULL, ","));
    candle.open = std::atof(std::strtok(NULL, ","));
    candle.close = std::atof(std::strtok(NULL, ","));
    candle.volume = std::atof(std::strtok(NULL, ""));
    candles.push_back(candle);
    lastClose = candle.close;
}

Settings &Calculator::get_settings()
{
    return settings;
}

double Calculator::calcSma(size_t period)
{
    double sum = 0;

    for (size_t i = candles.size() - period; i != candles.size(); i++)
        sum += candles[i].close;
    return sum / period;
}

double Calculator::calcEma(size_t period)
{
    double sma = calcSma(period);
    double smoothing = 2.0 / (period + 1);

    return (sma * (1 - smoothing)) + (smoothing * candles[candles.size() - 1].close);
}

double Calculator::calcNvt(size_t period)
{
    double nvt = candles[candles.size() - 1].close / candles[candles.size() - 1].volume;;
    double nvtPeriod = candles[candles.size() - period].close / candles[candles.size() - period].volume;

    return ((nvtPeriod - nvt) / fabs(nvt)) * 100;
}

bool Calculator::doBuy()
{
    double closeDiff = ((candles[candles.size() - 1].close - emaShort) / emaShort) * 100;

    buyMultiplier = 0;
    if (settings.getUSDT() < 5)
        return false;
    if (fabs(nvt - lastNvt) >= 50 && closeDiff <= -1.0) {
        buyMultiplier = 100;
        return true;
    }
    return false;
}

bool Calculator::doSell()
{
    double closeDiff = ((candles[candles.size() - 1].close - emaShort) / emaShort) * 100;

    if (settings.getBTC() == 0)
        return false;
    if (nvt < 0 || lastNvt > nvt)
        return false;
    if (fabs(nvt - lastNvt) >= 25)
        return true;
    if (closeDiff >= 1)
        return true;
    return false;
}

void Calculator::act()
{
    double order = 0;

    emaShort = calcEma(4);
    emaMedium = calcEma(21);
    emaLong = calcEma(42);
    nvt = calcNvt(15);
    buy = doBuy();
    sell = doSell();
    std::cerr << "------------------------------------------------------" << std::endl;
    std::cerr << "[CANDLES] lastClose=" << candles[candles.size() - 1].close << std::endl << std::endl;
    std::cerr << "[EMA'S] period(15)=" << emaShort << " period(30)=" << emaMedium << " period(60)=" << emaLong << std::endl << std::endl;
    std::cerr << "[GAPS] lastClose / emashort=" << ((candles[candles.size() - 1].close - emaShort) / emaShort) * 100 << std::endl << std::endl;
    std::cerr << "[NVT] period(15)=" << nvt << std::endl;
    std::cerr << "------------------------------------------------------" << std::endl;
    if (buy && !sell) {
        order = (settings.getUSDT() * buyMultiplier/100) / candles[candles.size() - 1].close;
        order -= order * 0.2/100;
        std::cout << "buy USDT_BTC " << order << std::endl;
        std::cerr << "[BUY] Bought for " << settings.getUSDT() << std::endl;
    }
    else if (sell && !buy) {
        std::cout << "sell USDT_BTC " << settings.getBTC() << std::endl;
        std::cerr << "[SELL] Sold for " << settings.getBTC() * candles[candles.size() - 1].close << std::endl;
    }
    else
        std::cout << "pass" << std::endl;
    lastClose = candles[candles.size() - 1].close;
    lastNvt = nvt;
}