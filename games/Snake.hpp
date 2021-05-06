/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCY-4-1-arcade-hugo.zaneguy
** File description:
** snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include <string>
#include <iostream>
#include "../games/Igames.hpp"
#include <type_traits>


class Snake :public Igames{
    public:
        Snake();
        ~Snake();
        void update(std::vector<Element>);
        void checkEvent(Input);
        std::vector<Element> getAllElement();
        void gameWin(){};
        int gameLoose();
    
        void CreateBackground(std::string path, int x, int y);
        void CreateApple(std::string path, int x, int y);
        Element CreateSnakeElement(std::string path, int x, int y);
        void CreateSnakeList();
        void CreateGameOver(std::string path, int x, int y);
        void CreateWallList();
        Element CreateWallElement(std::string path, int x, int y);
        void BodyFollow();
        void EatApple();

        std::vector<Element> vE;
        std::vector<Element> list_snake;
        std::vector<Element> list_wall;

        Element snake;
        Element apple;
        Element gameOver;
        Element wall;
};

#endif /* !SNAKE_HPP_ */
