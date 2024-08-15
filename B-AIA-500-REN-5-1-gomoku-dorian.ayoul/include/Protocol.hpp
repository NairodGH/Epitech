/*
** EPITECH PROJECT, 2022
** Protocol.hpp
** File description:
** Protocol.hpp
*/

#ifndef PROTOCOL_HPP
#define PROTOCOL_HPP

#include "Include.hpp"

class Protocol
{
    private:
        std::size_t _size = 0;
        std::vector<std::vector<char>> _board;
        bool _turn = false;
        bool _tempTurn = false;
        bool _boardInit = false;
        bool _boardCommand = false;
        char _player = 'X';
        char _enemy = 'O';

        std::size_t _timeoutTurn = 0;
        std::size_t _timeoutMatch = 0;
        std::size_t _maxMemory = 0;
        std::size_t _timeLeft = 0;
        std::size_t _game_type = 0;
        std::size_t _rule = 0;
        std::pair<std::size_t, std::size_t> _evaluate = {0, 0};
        std::string _folder = "";

        void initialize(std::string input);
        void turnAI(std::string input);
        void begin(std::string input);
        void board(std::string input);
        void info(std::string input);
        void end(std::string input);
        void about(std::string input);
        void preloadBoard(std::string input);
        void restart(std::string input);
        std::map<std::string, std::function<void(std::string)>> _listCommand = {
            {"START", std::bind(&Protocol::initialize, this, std::placeholders::_1)},
            {"TURN", std::bind(&Protocol::turnAI, this, std::placeholders::_1)},
            {"BEGIN", std::bind(&Protocol::begin, this, std::placeholders::_1)},
            {"BOARD", std::bind(&Protocol::board, this, std::placeholders::_1)},
            {"DONE", std::bind(&Protocol::board, this, std::placeholders::_1)},
            {"INFO", std::bind(&Protocol::info, this, std::placeholders::_1)},
            {"END", std::bind(&Protocol::end, this, std::placeholders::_1)},
            {"ABOUT", std::bind(&Protocol::about, this, std::placeholders::_1)},
            {"RESTART", std::bind(&Protocol::restart, this, std::placeholders::_1)}
        };

    public:
        Protocol() = default;
        ~Protocol() = default;
        void getCommand(std::string input);
        std::vector<std::vector<char>> &getBoard();
        bool getTurn() const;
        void setTurn(bool turn);
};

#endif /* !PROTOCOL_HPP */