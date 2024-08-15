/*
** EPITECH PROJECT, 2022
** SFML.cpp
** File description:
** SFML
*/

#include "SFML.hpp"

static const std::map<sf::Keyboard::Key, arc::DisplayKey> KEYS = {
	{sf::Keyboard::Return, arc::DisplayKey::D_ENTER},
    {sf::Keyboard::BackSpace, arc::DisplayKey::D_BACKSPACE},
	{sf::Keyboard::Space, arc::DisplayKey::D_SPACE},
	{sf::Keyboard::Escape, arc::DisplayKey::D_ESCAPE},
    {sf::Keyboard::Down, arc::DisplayKey::D_DOWN_ARROW},
    {sf::Keyboard::Up, arc::DisplayKey::D_UP_ARROW},
	{sf::Keyboard::Left, arc::DisplayKey::D_LEFT_ARROW},
	{sf::Keyboard::Right, arc::DisplayKey::D_RIGHT_ARROW},
    {sf::Keyboard::A, arc::DisplayKey::D_KEY_A},
	{sf::Keyboard::B, arc::DisplayKey::D_KEY_B},
	{sf::Keyboard::C, arc::DisplayKey::D_KEY_C},
	{sf::Keyboard::D, arc::DisplayKey::D_KEY_D},
	{sf::Keyboard::E, arc::DisplayKey::D_KEY_E},
	{sf::Keyboard::F, arc::DisplayKey::D_KEY_F},
	{sf::Keyboard::G, arc::DisplayKey::D_KEY_G},
	{sf::Keyboard::H, arc::DisplayKey::D_KEY_H},
	{sf::Keyboard::I, arc::DisplayKey::D_KEY_I},
	{sf::Keyboard::J, arc::DisplayKey::D_KEY_J},
	{sf::Keyboard::K, arc::DisplayKey::D_KEY_K},
	{sf::Keyboard::L, arc::DisplayKey::D_KEY_L},
	{sf::Keyboard::M, arc::DisplayKey::D_KEY_M},
	{sf::Keyboard::N, arc::DisplayKey::D_KEY_N},
	{sf::Keyboard::O, arc::DisplayKey::D_KEY_O},
	{sf::Keyboard::P, arc::DisplayKey::D_KEY_P},
	{sf::Keyboard::Q, arc::DisplayKey::D_KEY_Q},
	{sf::Keyboard::R, arc::DisplayKey::D_KEY_R},
	{sf::Keyboard::S, arc::DisplayKey::D_KEY_S},
	{sf::Keyboard::T, arc::DisplayKey::D_KEY_T},
	{sf::Keyboard::U, arc::DisplayKey::D_KEY_U},
	{sf::Keyboard::V, arc::DisplayKey::D_KEY_V},
	{sf::Keyboard::W, arc::DisplayKey::D_KEY_W},
	{sf::Keyboard::X, arc::DisplayKey::D_KEY_X},
	{sf::Keyboard::Y, arc::DisplayKey::D_KEY_Y},
	{sf::Keyboard::Z, arc::DisplayKey::D_KEY_Z},
    {sf::Keyboard::Numpad1, arc::DisplayKey::D_KEY_1},
	{sf::Keyboard::Numpad2, arc::DisplayKey::D_KEY_2},
	{sf::Keyboard::Numpad3, arc::DisplayKey::D_KEY_3},
	{sf::Keyboard::Numpad4, arc::DisplayKey::D_KEY_4},
	{sf::Keyboard::Numpad5, arc::DisplayKey::D_KEY_5},
	{sf::Keyboard::Numpad6, arc::DisplayKey::D_KEY_6},
	{sf::Keyboard::Numpad7, arc::DisplayKey::D_KEY_7},
	{sf::Keyboard::Numpad8, arc::DisplayKey::D_KEY_8},
	{sf::Keyboard::Numpad9, arc::DisplayKey::D_KEY_9},
	{sf::Keyboard::Numpad0, arc::DisplayKey::D_KEY_0},
    {sf::Keyboard::F1, arc::DisplayKey::D_F1},
	{sf::Keyboard::F2, arc::DisplayKey::D_F2},
	{sf::Keyboard::F3, arc::DisplayKey::D_F3},
	{sf::Keyboard::F4, arc::DisplayKey::D_F4},
	{sf::Keyboard::F5, arc::DisplayKey::D_F5},
	{sf::Keyboard::F6, arc::DisplayKey::D_F6},
	{sf::Keyboard::F7, arc::DisplayKey::D_F7},
	{sf::Keyboard::F8, arc::DisplayKey::D_F8},
	{sf::Keyboard::F9, arc::DisplayKey::D_F9}
};

void arc::SFML::initDisplay(void)
{
    sf::Texture texture;

    if (!texture.loadFromFile("graphicals/SFML/ressources/square.png"))
        return;
    this->_square.setTexture(texture);
    if (!texture.loadFromFile("graphicals/SFML/ressources/circle.png"))
        return;
    this->_circle.setTexture(texture);
    if (!texture.loadFromFile("graphicals/SFML/ressources/cross.png"))
        return;
    this->_cross.setTexture(texture);
    if (!_font.loadFromFile("graphicals/SFML/ressources/LiberationSerif-Regular.ttf"))
        return;
    this->_text.setFont(_font);
    this->_color[0] = sf::Color::Black;
    this->_color[DisplayColor::D_RED] = sf::Color::Red;
    this->_color[DisplayColor::D_BLUE] = sf::Color::Blue;
    this->_color[DisplayColor::D_GREEN] = sf::Color::Green;
    this->_color[DisplayColor::D_WHITE] = sf::Color::White;
    this->_color[DisplayColor::D_ORANGE] = {255, 165, 0};
    this->_color[DisplayColor::D_CYAN] = sf::Color::Cyan;
    this->_color[DisplayColor::D_PURPLE] = {199, 21, 133};
    this->_color[DisplayColor::D_YELLOW] = sf::Color::Yellow;
    this->_color[DisplayColor::D_LIME] = {0, 255, 0};
    this->_color[DisplayColor::D_BROWN] = {139, 69, 19};
    this->_color[DisplayColor::D_PINK] = {255, 192, 203};
    this->_color[DisplayColor::D_GRAY] = {128, 128, 128};
    this->_window.create(sf::VideoMode(720, 720), "SFML");
    this->_window.clear(sf::Color::Black);
    this->_window.display();
}

void arc::SFML::destroyDisplay(void)
{

}

void arc::SFML::drawSquare(unsigned char color, std::size_t posX, std::size_t posY)
{
    this->_square.setPosition({static_cast<float>(posX * 30), static_cast<float>(posY * 30)});
    this->_square.setColor(this->_color[color]);
    this->_window.draw(this->_square);
}

void arc::SFML::drawCircle(unsigned char color, std::size_t posX, std::size_t posY)
{
    this->_circle.setPosition({static_cast<float>(posX * 30), static_cast<float>(posY * 30)});
    this->_circle.setColor(this->_color[color]);
    this->_window.draw(this->_circle);
}

void arc::SFML::drawCross(unsigned char color, std::size_t posX, std::size_t posY)
{
    this->_cross.setPosition({static_cast<float>(posX * 30), static_cast<float>(posY * 30)});
    this->_cross.setColor(this->_color[color]);
    this->_window.draw(this->_cross);
}

void arc::SFML::drawLetter(unsigned char letter, unsigned char color, std::size_t posX, std::size_t posY)
{
    this->_text.setPosition(posX * 30, posY * 30);
    this->_text.setFillColor(this->_color[color]);
    this->_text.setString(std::string(1, letter));
    this->_window.draw(this->_text);
}

void arc::SFML::display(void)
{
    this->_window.display();
    this->_window.clear();
}

std::vector<arc::DisplayKey> arc::SFML::getKeys(void)
{
    sf::Event event{};

    _keys.clear();
	while (_window.pollEvent(event))
        if (event.type == sf::Event::KeyPressed && KEYS.find(event.key.code) != KEYS.end())
            _keys.push_back(KEYS.at(event.key.code));
    return _keys;
}