/*
** EPITECH PROJECT, 2022
** AI.cpp
** File description:
** AI.cpp
*/

#include "AI.hpp"

void printBoard(std::vector<std::vector<char>> &board)
{
    for (std::size_t i = 0; i < board.size(); i++) {
        std::cout << "DEBUG Board = ";
        for (std::size_t j = 0; j < board[i].size(); j++) {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "DEBUG ---------------------------------" << std::endl;
}

void printTree(tree_t tree)
{
    std::cout << "DEBUG Tree size = " << tree.children.size() << " Pos = " << tree.pos.first << " " << tree.pos.second << " Score = " << tree.score << std::endl;
    for (std::size_t i = 0; i < tree.children.size(); i++) {
        std::cout << "DEBUG children pos = " << tree.children[i].pos.first << " " << tree.children[i].pos.second << " Score = " << tree.children[i].score << std::endl;
        if (tree.children[i].children.size() > 0)
            printTree(tree.children[i]);
    }
    std::cout << "DEBUG ---------------------------------" << std::endl;
}

int AI::getEvaluateDiag(std::vector<std::vector<char>> &board, int depth, char chr, int i, int j, int &ret)
{
    int temp = 0;

    if (i + depth < board.size() && j + depth < board.size()) {
        temp = depth;
        if (board[i + 1][j + 1] == 'O')
            board[i][j] = 'O';
        while (board[i][j] == board[i + temp][j + temp] && temp > 0)
            temp--;
        if (temp == 0 && board[i + depth][j + depth] == chr)
            ret += 1;
        board[i][j] = 'X';
    }
    if (i - depth >= 0 && j - depth >= 0) {
        temp = depth;
        if (board[i - 1][j - 1] == 'O')
            board[i][j] = 'O';
        while (board[i][j] == board[i - temp][j - temp] && temp > 0)
            temp--;
        if (temp == 0 && board[i - depth][j - depth] == chr)
            ret += 1;
        board[i][j] = 'X';
    }
    if (i + depth < board.size() && j - depth >= 0) {
        temp = depth;
        if (board[i + 1][j - 1] == 'O')
            board[i][j] = 'O';
        while (board[i][j] == board[i + temp][j - temp] && temp > 0)
            temp--;
        if (temp == 0 && board[i + depth][j - depth] == chr)
            ret += 1;
        board[i][j] = 'X';
    }
    if (i - depth >= 0 && j + depth < board.size()) {
        temp = depth;
        if (board[i - 1][j + 1] == 'O')
            board[i][j] = 'O';
        while (board[i][j] == board[i - temp][j + temp] && temp > 0)
            temp--;
        if (temp == 0 && board[i - depth][j + depth] == chr)
            ret += 1;
        board[i][j] = 'X';
    }
    return ret;
}

int AI::getEvaluate(std::vector<std::vector<char>> &board, int depth, char chr, int i, int j)
{
    int ret = 0;
    int temp = 0;

    if (i + depth < board.size()) {
        temp = depth;
        if (board[i + 1][j] == 'O')
            board[i][j] = 'O';
        while (board[i][j] == board[i + temp][j] && temp > 0)
            temp--;
        if (temp == 0 && (board[i + depth][j] == chr))
            ret += 1;
        board[i][j] = 'X';
    }
    if (i - depth >= 0) {
        temp = depth;
        if (board[i - 1][j] == 'O')
            board[i][j] = 'O';
        while (board[i][j] == board[i - temp][j] && temp > 0)
            temp--;
        if (temp == 0 && (board[i - depth][j] == chr))
            ret += 1;
        board[i][j] = 'X';
    }
    if (j + depth < board.size()) {
        temp = depth;
        if (board[i][j + 1] == 'O')
            board[i][j] = 'O';
        while (board[i][j] == board[i][j + temp] && temp > 0)
            temp--;
        if (temp == 0 && (board[i][j + depth] == chr))
            ret += 1;
        board[i][j] = 'X';
    }
    if (j - depth >= 0) {
        temp = depth;
        if (board[i][j - 1] == 'O')
            board[i][j] = 'O';
        while (board[i][j] == board[i][j - temp] && temp > 0)
            temp--;
        if (temp == 0 && (board[i][j - depth] == chr))
            ret += 1;
        board[i][j] = 'X';
    }
    getEvaluateDiag(board, depth, chr, i, j, ret);
    return ret;
}

int AI::evaluate(std::vector<std::vector<char>> &board, int i, int j)
{
    int ret = 0;

    if (ret = this->getEvaluate(board, 4, this->_player, i, j))
        return 1000 * ret;
    if (ret = this->getEvaluate(board, 4, this->_enemy, i, j))
        return -1000 * ret;
    if (ret = this->getEvaluate(board, 3, this->_enemy, i, j))
        return -100 * ret;
    if (ret = this->getEvaluate(board, 3, this->_player, i, j))
        return 100 * ret;
    if (ret = this->getEvaluate(board, 2, this->_enemy, i, j))
        return -10 * ret;
    if (ret = this->getEvaluate(board, 2, this->_player, i, j))
        return 10 * ret;
    if (ret = this->getEvaluate(board, 1, this->_enemy, i, j))
        return -1 * ret;
    return 0;
}

void AI::splitMinimax(std::vector<std::vector<char>> &board, bool isMax, std::vector<struct tree_s> &children, int &best, int &ret)
{
    bool sup = isMax == false && ret < best ? true : isMax == true && ret > best ? true : false;;
    bool minus = isMax == false && ret > best ? true : isMax == true && ret < best ? true : false;

    if (sup) {
        while (children.size() > 1)
            children.erase(children.begin());
        best = ret;
    }
    else if (minus)
        children.pop_back();
}

int AI::minimax(std::vector<std::vector<char>> &board, int depth, bool isMax, tree_t &tree, std::vector<struct tree_s> &children, tree_t *lastChildren)
{
    int score = 0;
    
    if (lastChildren != nullptr)
        score = this->evaluate(board, lastChildren->pos.first, lastChildren->pos.second);
    else {
        score = this->evaluate(board, tree.pos.first, tree.pos.second);
        tree.score = score;
    }
    if (score >= 1000 || score <= -1000 || score == 0 || depth == 0)
        return score;
    if (isMax) {
        int best = -100000;
        int ret = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] != '_')
                    continue;
                board[i][j] = this->_player;
                children.push_back({{i, j}, {}, lastChildren, ret});
                ret = this->minimax(board, depth - 1, !isMax, tree, children[children.size() - 1].children, &children[children.size() - 1]);
                this->splitMinimax(board, isMax, children, best, ret);
                board[i][j] = '_';
            }
        }
        return best;
    } else {
        int best = 100000;
        int ret = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] != '_')
                    continue;
                board[i][j] = this->_enemy;
                children.push_back({{i, j}, {}, lastChildren, ret});
                ret = this->minimax(board, depth - 1, !isMax, tree, children[children.size() - 1].children, &children[children.size() - 1]);
                this->splitMinimax(board, isMax, children, best, ret);
                board[i][j] = '_';
            }
        }
        return best;
    }
}

void AI::getBestChildren(std::vector<struct tree_s> children, int &best)
{
    std::size_t i = 0;
    int temp = 0;

    while (i < children.size()) {
        if (children[i].children.size() > 0)
            getBestChildren(children[i].children, best);
        else {
            for (tree_t *tree = &children[i]; tree != nullptr; tree = tree->parent) {
                temp += children[i].score;
            }
            if (temp < best) {
                best = temp;
            }
            temp = 0;
            i++;
        }
    }
}

void AI::selectBestMove(std::vector<std::vector<char>> &board, std::vector<tree_t> &tree)
{
    std::vector<int> score(static_cast<int>(tree.size()));
    std::vector<std::pair<int, int>> pos(static_cast<int>(tree.size()));
    std::vector<std::pair<int, int>> bestMove = {std::make_pair(0, 0)};

    for (int i = 0, best = 0; i < tree.size(); i++, best = 0) {
        score[i] = tree[i].score;
        /* if (tree[i].children.size() > 0) {
            getBestChildren(tree[i].children, best);
            score[i] += best;
        } */
        pos[i] = tree[i].pos;
    }
    for (int i = 0, max = 0; i < score.size(); i++) {
        if (score[i] < 0 && -score[i] > max) {
            max = -score[i];
            bestMove.clear();
            bestMove.push_back(pos[i]);
        }
        else if (-score[i] == max)
            bestMove.push_back(pos[i]);
        else {
            if (score[i] > max) {
                max = score[i];
                bestMove.clear();
                bestMove.push_back(pos[i]);
            }
        }
    }
    int random = rand() % bestMove.size();
    std::cout << bestMove[random].first << "," << bestMove[random].second << std::endl;
    board[bestMove[random].first][bestMove[random].second] = this->_player;
}

void AI::play(std::vector<std::vector<char>> &board)
{
    std::vector<tree_t> tree;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[i][j] == '_') {
				board[i][j] = this->_player;
                tree.resize(tree.size() + 1);
                tree[tree.size() - 1].pos = std::make_pair(i, j);
                tree[tree.size() - 1].parent = nullptr;
				minimax(board, 1, false, tree[tree.size() - 1], tree[tree.size() - 1].children, nullptr);
                board[i][j] = '_';
			}
            else
                tree.push_back({std::make_pair(i, j), {}, 0});
		}
	}
    this->selectBestMove(board, tree);
}