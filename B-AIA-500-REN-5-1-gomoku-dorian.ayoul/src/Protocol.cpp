/*
** EPITECH PROJECT, 2022
** Protocol.cpp
** File description:
** Protocol.cpp
*/

#include "Protocol.hpp"

std::vector<std::vector<char>> &Protocol::getBoard()
{
    return this->_board;
}

bool Protocol::getTurn() const
{
    return this->_turn;
}

void Protocol::setTurn(bool turn)
{
    this->_turn = turn;
}

void Protocol::initialize(std::string input)
{
    std::smatch match;

    if (std::regex_match(input, match, std::regex("START ([0-9]+)"))) {
        this->_size = std::stoi(match[1]);
        if (this->_size < 1) {
            std::cout << "ERROR message - unsupported size or other error" << std::endl;
            return;
        }
        this->_board.resize(this->_size);
        for (std::size_t i = 0; i < this->_size; i++)
            this->_board[i].resize(this->_size);
        for (std::size_t i = 0; i < this->_size; i++) {
            for (std::size_t j = 0; j < this->_size; j++)
                this->_board[i][j] = '_';
        }
        std::cout << "OK" << std::endl;
    } else
        std::cout << "ERROR message - unsupported size or other error" << std::endl;
}

void Protocol::turnAI(std::string input)
{
    std::smatch match;

    if (std::regex_match(input, match, std::regex("TURN ([0-9]+),([0-9]+)"))) {
        this->_board[std::stoi(match[1])][std::stoi(match[2])] = this->_enemy;
        this->_turn = true;
    } else
        std::cout << "ERROR message - Invalid turn input" << std::endl;
}

void Protocol::begin(std::string input)
{
    std::smatch match;

    if (std::regex_match(input, match, std::regex("BEGIN"))) {
        std::cout << "10,10" << std::endl;
        this->_board[10][10] = this->_player;
    } else
        std::cout << "ERROR message - Invalid begin input" << std::endl;
}

void Protocol::board(std::string input)
{
    std::smatch match;

    if (std::regex_match(input, match, std::regex("BOARD"))) {
        this->_boardCommand = !this->_boardCommand;
    } else if (std::regex_match(input, match, std::regex("DONE"))) {
        this->_boardCommand = !this->_boardCommand;
        this->_turn = true;
        this->_boardInit = false;
    } else
        std::cout << "ERROR message - Invalid board input" << std::endl;
}

void Protocol::preloadBoard(std::string input)
{
    std::smatch match;

    if (std::regex_match(input, match, std::regex("([0-9]+),([0-9]+),([0-9]+)"))) {
        this->_board[std::stoi(match[1])][std::stoi(match[2])] = (match[3] == "1" ? 'X' : 'O');
        if (!this->_boardInit)
            this->_tempTurn = (match[3] == "1" ? false : true);
        else
            this->_tempTurn = !this->_tempTurn;
        this->_boardInit = true;
    } else
        std::cout << "ERROR message - Invalid preload input" << std::endl;
}

void Protocol::info(std::string input)
{
    std::smatch match;

    if (std::regex_match(input, match, std::regex("INFO timeout_turn ([0-9]+)"))) {
        this->_timeoutTurn = std::stoi(match[1]);
    } else if (std::regex_match(input, match, std::regex("INFO timeout_match ([0-9]+)"))) {
        this->_timeoutMatch = std::stoi(match[1]);
    } else if (std::regex_match(input, match, std::regex("INFO max_memory ([0-9]+)"))) {
        this->_maxMemory = std::stoi(match[1]);
    } else if (std::regex_match(input, match, std::regex("INFO time_left ([0-9]+)"))) {
        this->_timeLeft = std::stoi(match[1]);
    } else if (std::regex_match(input, match, std::regex("INFO game_type ([0-9]+)"))) {
        this->_game_type = std::stoi(match[1]);
    } else if (std::regex_match(input, match, std::regex("INFO rule ([0-9]+)"))) {
        this->_rule = std::stoi(match[1]);
    } else if (std::regex_match(input, match, std::regex("INFO evaluate ([0-9]+) ([0-9]+)"))) {
        this->_evaluate.first = std::stoi(match[1]);
        this->_evaluate.second = std::stoi(match[2]);
    } else if (std::regex_match(input, match, std::regex("INFO folder (.*)"))) {
        this->_folder = match[1];
    } else
        std::cout << "ERROR message - Invalid info input" << std::endl;
}

void Protocol::end(std::string input)
{
    std::smatch match;

    if (std::regex_match(input, match, std::regex("END"))) {
        this->_board.clear();
        this->_size = 0;
        this->_turn = false;
        this->_boardCommand = false;
        exit(0);
    } else
        std::cout << "ERROR message - Invalid end input" << std::endl;
}

void Protocol::about(std::string input)
{
    std::smatch match;

    if (std::regex_match(input, match, std::regex("ABOUT"))) {
        std::cout << "name=\"Gomoku\", version=\"0.1\", author=\"Dorian & Xavier\", country=\"France\"" << std::endl;
    } else
        std::cout << "ERROR message - Invalid about input" << std::endl;
}

void Protocol::restart(std::string input)
{
    std::smatch match;

    if (std::regex_match(input, match, std::regex("RESTART"))) {
        for (std::size_t i = 0; i < this->_size; i++) {
            for (std::size_t j = 0; j < this->_size; j++)
                this->_board[i][j] = '_';
        }
        this->_turn = false;
        this->_boardCommand = false;
        std::cout << "OK" << std::endl;
    } else
        std::cout << "ERROR message - Invalid restart input" << std::endl;
}

void Protocol::getCommand(std::string input)
{
    std::smatch match;
    
    std::cout << "DEBUG - " << input << std::endl;
    if (std::regex_match(input, match, std::regex("([A-Z]+)(.*)"))) { // ([A-Z]+)(.*)\r\n
        if (this->_listCommand.find(match[1]) != this->_listCommand.end()) {
            this->_listCommand[match[1]](input);
        }
        else
            throw std::invalid_argument("Invalid command");
    } else if (this->_boardCommand) {
        preloadBoard(input);
    } else
        throw std::invalid_argument("Invalid command");
}