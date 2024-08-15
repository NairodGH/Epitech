/*
** EPITECH PROJECT, 2022
** Menu.hpp
** File description:
** Menu
*/

#include "Menu.hpp"

void arc::Menu::initGame(void)
{
    std::ifstream configFile("./lib/libs.config");
    bool is_graph = true;
    std::vector<int> tmp;

    _score = 0;
    _pos = 1;
    _state = arc::State::START;
    _gameName = "menu";
    _playerName = "";
    for (std::string currentLine; std::getline(configFile, currentLine);) {
        if (currentLine == "graphicals:")
            continue;
        if (currentLine == "games:") {
            is_graph = false;
            continue;
        }
        currentLine.insert(0, "./lib/");
        if (is_graph)
            _graphPathes.push_back(currentLine);
        else
            _gamePathes.push_back(currentLine);
    }
    configFile.close();
    for (size_t i = 0; i < _playerName.size(); i++)
        tmp.push_back(_playerName[i]);
    _map.push_back(tmp);
    tmp.clear();
    for (size_t i = 0; i < _graphPathes.size(); i++) {
        for (size_t j = 0; j < _graphPathes[i].size(); j++) {
            tmp.push_back(_graphPathes[i][j]);
        }
        _map.push_back(tmp);
        tmp.clear();
    }
    for (size_t i = 0; i < _gamePathes.size(); i++) {
        for (size_t j = 0; j < _gamePathes[i].size(); j++) {
            tmp.push_back(_gamePathes[i][j]);
        }
        _map.push_back(tmp);
        tmp.clear();
    }
    _map[_pos].push_back('<');
}

void arc::Menu::destroyGame(void)
{
    
}

void arc::Menu::update(std::vector<arc::GameKey> keys)
{
    if (keys.empty())
        return;
    if (keys.back() == arc::GameKey::G_DOWN_ARROW && _pos < _graphPathes.size() + _gamePathes.size()) {
        _map[_pos].pop_back();
        _pos++;
        _map[_pos].push_back('<');
    }
    if (keys.back() == arc::GameKey::G_UP_ARROW && _pos > 1) {
        _map[_pos].pop_back();
        _pos--;
        _map[_pos].push_back('<');
    }
    if (keys.back() == arc::GameKey::G_ENTER) {
        std::stringstream result;
        std::copy(_map[_pos].begin(), _map[_pos].end(), std::ostream_iterator<char>(result));
        _gameName = result.str();
    }
}

void arc::Menu::setGameState(arc::State state)
{
    _state = state;
}

arc::State arc::Menu::getGameState(void)
{
    return _state;
}

std::vector<std::vector<int>> arc::Menu::getMap(void)
{
    return _map;
}

std::size_t arc::Menu::getScore(void)
{
    return 10;
}


std::string arc::Menu::getPlayerName(void)
{
    return _playerName;
}

std::string arc::Menu::getGameName(void)
{
    return _gameName;
}

void  arc::Menu::setPlayerName(std::string username)
{
    _playerName = username;
}