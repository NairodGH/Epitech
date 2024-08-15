/*
** EPITECH PROJECT, 2022
** core.cpp
** File description:
** core
*/

#include "core.hpp"
#include <chrono>
#include <thread>

arc::Core::Core(const std::string &path) :
_graphHandle(nullptr), _gameHandle(nullptr), _game(nullptr), _graph(nullptr),
_timer(std::chrono::steady_clock::now()), _username(""), _score(0), _currentGame("menu"),
_selectedGame(0), _selectedGraph(0)
{
	std::ifstream lib(path);

    if (lib.fail())
        throw Error("Couldn't open initial graphic library.");
    _graphPathes.push_back(path);
    getLibs();
    mainLoop();
}

void arc::Core::getLibs()
{
    std::ifstream configFile("./lib/libs.config");
    std::string currentLine = "";
    bool is_graph = true;
    std::ifstream currentLib;

    if (configFile.fail())
        throw Error("Couldn't open config file in lib folder.");
    std::getline(configFile, currentLine);
    if (currentLine != "graphicals:")
        throw Error("First line of lib config file isnt 'graphicals:'.");
    for (char elf[5], magicNb[] = {0x7f, 'E', 'L', 'F', 0}; std::getline(configFile, currentLine);) {
        if (currentLine == "games:") {
            is_graph = false;
            continue;
        }
        currentLine.insert(0, "./lib/");
        if (currentLine == _graphPathes[0])
            continue;
        if (currentLine.find(".so") == std::string::npos)
            throw Error(currentLine + " isn't a valid .so dynamic library.");
        currentLib.open(currentLine);
        if (currentLib.fail())
		    throw Error(currentLine + " cannot be opened/read.");
	    currentLib.read(elf, 4);
        if (std::string(elf) != magicNb) {
            currentLib.close();
            throw Error(currentLine + " isn't a valid ELF file.");
        }
        if (is_graph)
            _graphPathes.push_back(currentLine);
        else
            _gamePathes.push_back(currentLine);
        currentLib.close();
    }
    configFile.close();
    if (!_graphPathes.size() || !_gamePathes.size())
        throw Error("Provide at least 1 graphical lib and 1 game lib in config file.");
}

void arc::Core::loadLib(const std::string &libPath, bool is_graph)
{
	arc::IDisplay *(*graph)() = nullptr;
    arc::IGame *(*game)() = nullptr;

    if (is_graph) {
        if (_graphHandle == nullptr && (_graphHandle = dlopen(libPath.c_str(), RTLD_LAZY))) {
            *(void **)(&graph) = dlsym(_graphHandle, "entryPoint");
            _graph = graph();
            return;
        }
        else
		    throw Error("Couldn't load " + libPath + ": " + dlerror());
    }
	if (_gameHandle == nullptr && (_gameHandle = dlopen(libPath.c_str(), RTLD_LAZY))) {
        *(void **)(&game) = dlsym(_gameHandle, "entryPoint");
        _game = game();
	}
    else {
		throw Error("Couldn't load " + libPath + ": " + dlerror());
    }
}

bool arc::Core::getUsername()
{
    for (size_t i = 0;; i = 0) {
        for (std::vector<DisplayKey> keys;;) {
            if ((keys = _graph->getKeys()).empty())
                continue;
            if (keys.back() == arc::D_ESCAPE)
                return false;
            if (keys.back() == arc::D_ENTER)
                return true;
            if (keys.back() == arc::D_BACKSPACE && !_username.empty())
                _username.pop_back();
            if (arc::D_RIGHT_ARROW < keys.back() && keys.back() < arc::D_F1 &&  _username.size() < 16)
                _username += (keys.back() < arc::D_KEY_1 ? keys.back() + 57 : keys.back() + 14);
            break;
        }
        for (; !_username.empty() && i < _username.size(); i++)
            _graph->drawLetter(_username[i], 4, i, 0);
        for (; i < 16; i++)
            _graph->drawLetter(' ', 4, i, 0);
        _graph->display();
    }
}

void arc::Core::readMap()
{
    std::vector<std::vector<int>> map = _game->getMap();
    int first = 0;
    int second = 0;
    unsigned char *tmp = NULL;

    for (size_t x = 0; x != map.size(); x++) {
        for (size_t y = 0; y != map[x].size(); y++) {
            tmp = (unsigned char*)&map[x][y];
            first = *(tmp + 1);
            second = *(tmp + 2);
            if (first == arc::Shape::CIRCLE)
                _graph->drawCircle(second, x, y);
            else if (first == arc::Shape::SQUARE)
                _graph->drawSquare(second, x, y);
            else if (first == arc::Shape::CROSS)
                _graph->drawCross(second, x, y);
            else
                _graph->drawLetter(map[x][y], 4, y, x);
        }
    }
}

void arc::Core::destroy()
{
    _graph->destroyDisplay();
    _game->destroyGame();
    unloadLib(1);
    unloadLib(0);
}

void arc::Core::changeLib()
{
    if (std::find(_graphPathes.begin(), _graphPathes.end(), _currentGame) != _graphPathes.end()) {
        unloadLib(1);
        loadLib(_currentGame, 1);
        _graph->initDisplay();
        return;
    }
    if (std::find(_gamePathes.begin(), _gamePathes.end(), _currentGame) != _gamePathes.end()) {
        unloadLib(0);
        loadLib(_currentGame, 0);
        _game->initGame();
    }
}

void arc::Core::checkFunctionKey(std::vector<DisplayKey> dKeys)
{
    if (dKeys.back() == arc::DisplayKey::D_F5 && _selectedGraph > 0) {
        unloadLib(1);
        _selectedGraph--;
        loadLib(_graphPathes[_selectedGraph], 1);
        _graph->initDisplay();
    }
    if (dKeys.back() == arc::DisplayKey::D_F6 && _selectedGraph < _graphPathes.size()) {
        unloadLib(1);
        _selectedGraph++;
        loadLib(_graphPathes[_selectedGraph], 1);
        _graph->initDisplay();
    }
    if (dKeys.back() == arc::DisplayKey::D_F7 && _selectedGame > 0) {
        unloadLib(0);
        _selectedGame--;
        loadLib(_gamePathes[_selectedGame], 0);
        _game->initGame();
    }
    if (dKeys.back() == arc::DisplayKey::D_F8 && _selectedGame < _gamePathes.size()) {
        unloadLib(0);
        _selectedGame++;
        loadLib(_gamePathes[_selectedGame], 0);
        _game->initGame();
    }
}

bool arc::Core::updateKeys(std::vector<DisplayKey> &dKeys, std::vector<GameKey> &gKeys)
{
    if (!dKeys.empty()) {
        gKeys.push_back((GameKey)dKeys.back());
        if (dKeys.back() == arc::DisplayKey::D_ESCAPE) {
            destroy();
            return false;
        }
        if (_game->getGameName() != _currentGame) {
            _currentGame = _game->getGameName();
            _currentGame.pop_back();
            changeLib();
        }
        _game->update(gKeys);
        checkFunctionKey(dKeys);
    }
    if (dKeys.empty())
        _game->update(std::vector<GameKey>());
    return true;
}

void arc::Core::displayScore()
{
    if (_game->getScore() < 10)
        _graph->drawLetter(((char*)(std::to_string(_game->getScore()).c_str()))[0], 8, 0, 0);
}

void arc::Core::waitClock(std::vector<DisplayKey> &dKeys)
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    for (std::vector<DisplayKey> tmp; std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <= 300000;) {
        tmp = _graph->getKeys();
        if (tmp.size() > 0) {
            dKeys.push_back(tmp.back());
            tmp.clear();
        }
        end = std::chrono::steady_clock::now();
    }
}

void arc::Core::mainLoop()
{
    std::vector<DisplayKey> dKeys;

    loadLib(_graphPathes[_selectedGraph], 1);
    loadLib(_gamePathes[_selectedGame], 0);
    _graph->initDisplay();
    if (!getUsername()) {
        destroy();
        return;
    }
    _game->setPlayerName(_username);
    _game->initGame();
    for (std::vector<GameKey> gKeys;;) {
        if (!updateKeys(dKeys, gKeys))
            return;
        readMap();
        displayScore();
        _graph->display();
        gKeys.clear();
        dKeys.clear();
        waitClock(dKeys);
    }
}

void arc::Core::unloadLib(bool is_graph)
{
    if (is_graph) {
        _graph->destroyDisplay();
        if (_graphHandle != nullptr)
		    dlclose(_graphHandle);
        _graphHandle = nullptr;
        _graph = nullptr;
        return;
    }
    _game->destroyGame();
    if (_gameHandle != nullptr)
        dlclose(_gameHandle);
    _gameHandle = nullptr;
    _game = nullptr;
}