/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Sfml
*/

//g++ -shared -o libsfml.so Sfml.o -lsfml-graphics -lsfml-window -lsfml-system

//g++ -c Sfml.cpp
//g++ Sfml.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
//./sfml-app

#include "ISfml.hpp"

extern "C"
{
    IgraphicLib* loadGraphicLib() {
        return (new Sfml());
    }
}

Sfml::Sfml() : window(sf::VideoMode(1200, 800), "Arcade SFML"), event()
{
    if(!this->font.loadFromFile("./sfml/font/font.ttf"))
        throw("Failed to load fond");
}

Sfml::~Sfml()
{
}

void Sfml::drawText(const std::string &_text, int x, int y, int size, int r, int g, int b)
{
    this->text.setFillColor(sf::Color(r, g, b));
    this->text.setFont(font);
    this->text.setCharacterSize(size);
    this->text.setPosition(x *16, y *16 );
    this->text.setString(_text);
    this->window.draw(text);
}

void Sfml::initItem(std::string test, int x, int y, int w , int h) {
    (void)w;
    (void)h;
    if(!this->texture.loadFromFile(test))
        throw("Failed to load image wsh");
    this->sprite.setTexture(texture);
    this->sprite.setPosition(sf::Vector2f(x, y));
}

void Sfml::initItem(std::vector <Element> v_element)
{   
    for (const auto &vE : v_element) {
        if (!this->texture.loadFromFile(vE.path))
            throw("Failed to load image wsh");
        this->sprite.setTexture(this->texture);
        this->sprite.setPosition(sf::Vector2f(vE.posx, vE.posy));
        this->window.draw(sprite);
    }
};

Input Sfml::handleKey() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        return(Up);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        return(Left);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        return(Right);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        return(Down);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        return(PreviousLib);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        return(NextLib);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        return(Quit);
    }
     else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        return(Menue);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        return(Start);
    }
    return(Null);
}

void Sfml::clear()
{
    this->window.clear();
}

std::string Sfml::getValue()
{
    return (this->value);
}

void Sfml::display() {
    this->window.setFramerateLimit(60);
    while (this->window.pollEvent(event))
    {
    if (event.type == sf::Event::Closed) {
        this->window.close();
        this->value = "close";
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) 
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            this->window.close();
    }
    // window.clear(sf::Color::Black);
    this->window.display();
}