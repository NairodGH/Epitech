/*
** EPITECH PROJECT, 2022
** AI.hpp
** File description:
** AI.hpp
*/

#ifndef AI_HPP
#define AI_HPP

#include "Include.hpp"

typedef struct tree_s {
    std::pair<std::size_t, std::size_t> pos; 
    std::vector<struct tree_s> children;
    struct tree_s *parent;
    int score;
} tree_t;

class AI {
    private:
        char _player = 'X';
        char _enemy = 'O';
        bool checkClose(std::vector<std::vector<char>> &board, int x, int y);
        int getEvaluate(std::vector<std::vector<char>> &board, int depth, char chr, int i, int j);
        int getEvaluateDiag(std::vector<std::vector<char>> &board, int depth, char player, int i, int j, int &ret);
        int evaluate(std::vector<std::vector<char>> &board, int i, int j);
        int minimax(std::vector<std::vector<char>> &board, int depth, bool isMax, tree_t &tree, std::vector<struct tree_s> &children, tree_t *lastChildren);
        void splitMinimax(std::vector<std::vector<char>> &board, bool isMax, std::vector<struct tree_s> &children, int &best, int &ret);
        void selectBestMove(std::vector<std::vector<char>> &board, std::vector<tree_t> &tree);
        void getBestChildren(std::vector<struct tree_s> children, int &score);

    public:
        AI() = default;
        ~AI() = default;
        void play(std::vector<std::vector<char>> &board);
};

#endif /* !AI_HPP */