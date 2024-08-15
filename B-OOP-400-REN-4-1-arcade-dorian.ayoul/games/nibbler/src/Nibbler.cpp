/*
** EPITECH PROJECT, 2022
** IGame.hpp
** File description:
** IGame
*/

#include "Nibbler.hpp"

void arc::Nibbler::putSnakeInMap()
{
    std::vector<std::pair<int, int>> tmp = _snake.getPosSnake();

    for (size_t x = 0; x != _map.size(); x++) {
        for (size_t y = 0; y != _map[x].size(); y++) {
            if (_map[x][y] == 3)
                _map[x][y] = 0;
        }
    }
    for (std::vector<std::pair<int, int>>::iterator it = tmp.begin(); it != tmp.end(); ++it)
        _map[it->first][it->second] = 3;
}

void arc::Nibbler::update(std::vector<arc::GameKey> key)
{
    std::vector<std::pair<int, int>> tmp_snake;
    bool mov = false;

    for (std::vector<arc::GameKey>::iterator it = key.begin() ; it != key.end(); ++it) {
        if ((*it) == arc::GameKey::G_UP_ARROW && !mov) {
            if (_snake.getLastDir() != Dir::North) {
                mov = true;
                _snake.moveSnake(Dir::South);
            }
        }
        else if ((*it) == arc::GameKey::G_DOWN_ARROW && !mov) {
            if (_snake.getLastDir() != Dir::South) {
                mov = true;
                _snake.moveSnake(Dir::North);
            }
        }
        else if ((*it) == arc::GameKey::G_LEFT_ARROW && !mov) {
            if (_snake.getLastDir() != Dir::Est) {
                mov = true;
                _snake.moveSnake(Dir::West);
            }
        }
        else if ((*it) == arc::GameKey::G_RIGHT_ARROW && !mov) {
            if (_snake.getLastDir() != Dir::West) {
                mov = true;
                _snake.moveSnake(Dir::Est);
            }
        }
    }
    if (!mov)
        _snake.moveSnake(_snake.getLastDir());
    tmp_snake = _snake.getPosSnake();
    if (_map[tmp_snake.begin()->first][tmp_snake.begin()->second] == 2) {
        _snake.growsSnake();
        _map[tmp_snake.begin()->first][tmp_snake.begin()->second] = 0;
        this->_fruit--;
    }
    if (this->_fruit == 0 || _snake.checkDeath(this->_map)) {
        std::ifstream file;
        file.open("games/nibbler/ressources/map1.txt");
        if (!file.is_open())
            return;
        this->_map.clear();
        this->_snake.createSnake();
        if (_fruit != 0)
            this->_score = 0;
        else
            this->_score += 1;
        this->_fruit = 10 + (5 * this->_score);
        fillMap(file);
        this->_snake.createSnake();
        putSnakeInMap();
        return;
    }
    putSnakeInMap();
}

void arc::Nibbler::fillMap(std::ifstream &file)
{
    std::string line;
    size_t x = 0;
    std::vector<std::pair<int, int>> fruits;
    std::vector<int> first;

    while (std::getline(file, line)) {
        for (std::size_t j = 0; j != line.size(); j++) {
            if (line[j] == ' ')
                first.push_back(0);
            if (line[j] == 'x')
                first.push_back(1);
        }
        _map.push_back(first);
        first.clear();
        x++;
    }
    fruits = this->_utils.generateRand(this->_map, this->_fruit, std::vector<int> {1});
    for (std::vector<std::pair<int, int>>::iterator it = fruits.begin() ; it != fruits.end(); ++it)
        _map[it->first][it->second] = 2;
}

void arc::Nibbler::initGame()
{
    std::ifstream file;

    file.open("games/nibbler/ressources/map1.txt");
    if (!file.is_open())
        return;
    _gameName = "./libs/arcade_nibbler.so";
    _playerName = "";
    this->_fruit = 10;
    fillMap(file);
    this->_score = 0;
    this->_state = arc::State::START;
    this->_snake.createSnake();
    putSnakeInMap();
}

void arc::Nibbler::destroyGame()
{

}

void arc::Nibbler::setGameState(arc::State state)
{
    this->_state = state;
}

std::vector<std::vector<int>> arc::Nibbler::getMap()
{
    return this->_utils.convertMap(this->_map);
}

arc::State arc::Nibbler::getGameState()
{
    return this->_state;
}

std::size_t arc::Nibbler::getScore()
{
    return this->_score;
}

std::string arc::Nibbler::getPlayerName(void)
{
    return _playerName;
}

std::string arc::Nibbler::getGameName(void)
{
    return _gameName;
}

void  arc::Nibbler::setPlayerName(std::string username)
{
    _playerName = username;
}