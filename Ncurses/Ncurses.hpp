/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCY-4-1-arcade-hugo.zaneguy
** File description:
** Ncurses
*/

#include "../include/IgraphicLib.hpp"
#include <curses.h>
#include <string.h>
#include <iostream>

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

class Ncurses : public IgraphicLib {
    public:
        Ncurses();
        ~Ncurses();
        void display();
        void initItem(std::string test, int x, int y, int w, int h) {(void)test; (void)x ; (void)y ;(void)w; (void)h ;};
        void initItem(std::vector <Element> v_element);
        std::pair<int, int> resizing(int x, int y, WINDOW *window);
        void drawText(const std::string &_text, int x, int y, int size, int r, int g, int b);
        Input handleKey();
        void clear();
        std::string getValue(){return this->value;};
        int hk; //handlekeycode
        WINDOW  *_window;

        std::string value;

    protected:
    private:
};

#endif /* !NCURSES_HPP_ */
