/*
** EPITECH PROJECT, 2022
** IGame.hpp
** File description:
** IGame
*/

#include "Pacman.hpp"

void arc::Pacman::putGhostInMap(void)
{
    for (size_t x = 0; x != _map.size(); x++) {
        for (size_t y = 0; y != _map[x].size(); y++) {
            if (_map[x][y] == 4)
                _map[x][y] = 0;
        }
    }
    _map[this->_ghost[0].getPosGhost().first][this->_ghost[0].getPosGhost().second] = 4;
    _map[this->_ghost[1].getPosGhost().first][this->_ghost[1].getPosGhost().second] = 4;
    _map[this->_ghost[2].getPosGhost().first][this->_ghost[2].getPosGhost().second] = 4;
    _map[this->_ghost[3].getPosGhost().first][this->_ghost[3].getPosGhost().second] = 4;
}

void arc::Pacman::putGommeInMap(void)
{
    for (std::vector<std::pair<int, int>>::iterator it = _gommePos.begin() ; it != _gommePos.end(); ++it) {
        if (_map[it->first][it->second] != 3 && _map[it->first][it->second] != 4 && _map[it->first][it->second] != 5)
            _map[it->first][it->second] = 2;
    }
}

void arc::Pacman::update(std::vector<arc::GameKey> key)
{
    std::pair<int, int> tmp_ghost;
    bool mov = false;

    for (std::vector<arc::GameKey>::iterator it = key.begin() ; it != key.end(); ++it) {
        if ((*it) == arc::GameKey::G_UP_ARROW && !mov) {
            mov = true;
            _pac.movePac(Dir::North, _map);
        }
        if ((*it) == arc::GameKey::G_DOWN_ARROW && !mov) {
            mov = true;
            _pac.movePac(Dir::South, _map);
        }
        if ((*it) == arc::GameKey::G_LEFT_ARROW && !mov) {
            mov = true;
            _pac.movePac(Dir::West, _map);
        }
        if ((*it) == arc::GameKey::G_RIGHT_ARROW && !mov) {
            mov = true;
            _pac.movePac(Dir::Est, _map);
        }
    }
    if (!mov)
        _pac.movePac(_pac.getLastDir(), _map);
    if (_pac.checkDeath(this->_map))
        return;
    for (size_t nb_ghost = 0; nb_ghost != 4; nb_ghost++) {
        _ghost[nb_ghost].moveGhost(this->_map);
    }
    if (this->_gommePos.size() == 0)
        return;
    putGhostInMap();
    putGommeInMap();
}

void arc::Pacman::fillMap(std::ifstream &file)
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
            if (line[j] == 'o')
                this->_gommePos.push_back(std::pair<int, int>(x, j));
        }
        _map.push_back(first);
        first.clear();
        x++;
    }
}

void arc::Pacman::initGame()
{
    std::ifstream file;

    srand(time(NULL));
    file.open("ressources/Pacman/map1.txt");
    if (!file.is_open())
        return;
    fillMap(file);
    _gameName = "./libs/arcade_pacman.so";
    _playerName = "";
    this->_score = 0;
    this->_state = arc::State::START;
    this->_ghost[0].createGhost(std::pair<int, int>(11, 13));
    this->_ghost[1].createGhost(std::pair<int, int>(12, 13));
    this->_ghost[2].createGhost(std::pair<int, int>(11, 16));
    this->_ghost[3].createGhost(std::pair<int, int>(12, 16));
    this->_pac.createPac();
    putGhostInMap();
    putGommeInMap();
}

void arc::Pacman::destroyGame()
{

}

void arc::Pacman::setGameState(arc::State state)
{
    this->_state = state;
}

std::vector<std::vector<int>> arc::Pacman::getMap()
{
    return this->_utils.convertMap(this->_map);
}

arc::State arc::Pacman::getGameState()
{
    return this->_state;
}

std::size_t arc::Pacman::getScore()
{
    return this->_score;
}

std::string arc::Pacman::getPlayerName(void)
{
    return _playerName;
}

std::string arc::Pacman::getGameName()
{
    return _gameName;
}

void  arc::Pacman::setPlayerName(std::string username)
{
    _playerName = username;
}