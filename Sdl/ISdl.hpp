/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCY-4-1-arcade-hugo.zaneguy
** File description:
** Isdl
*/

#ifndef ISDL_HPP_
#define ISDL_HPP_

#include "../include/IgraphicLib.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "SDL2/SDL_image.h"

class Sdl : public IgraphicLib
{
public:
    Sdl();
    ~Sdl();
    void display();
    void initItem(std::string test, int x, int y, int width, int height);
    void initItem(std::vector <Element> v_element);
    void drawText(const std::string &_text, int x, int y, int size, int r, int g, int b);
    void clear();
    Input handleKey();
    std::string getValue();
    // void clear();
    // void refresh();
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    SDL_Surface *surface;
    SDL_Texture *texture;
    TTF_Font *font;

    std::string value;
};

#endif /* !ISDL_HPP_ */