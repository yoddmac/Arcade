/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Isfml
*/

#ifndef ISFML_HPP_
#define ISFML_HPP_

#include "../include/IgraphicLib.hpp"
#include <string>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

class Sfml : public IgraphicLib {
    public:
        Sfml();
        ~Sfml();
        void display();
        void initItem(std::string test, int x, int y, int w, int h);
        void initItem(std::vector <Element>);
        void drawText(const std::string &_text, int x, int y, int size, int r, int g, int b);
        Input handleKey();
        void clear();
        std::string getValue();
        // void Update(); //upadate game
        // void Move(); //move player
        // void Destroy(); //window/sprite/textur
        sf::RenderWindow window;
        sf::Event event;
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Text text;
        sf::Font font;
        std::string value;
};

#endif /* !ISFML_HPP_ */
