/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** GraphicLib
*/

#ifndef GRAPHICLIB_HPP_
#define GRAPHICLIB_HPP_

#include <string>
#include <iostream>
#include <type_traits>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "helper.hpp"

class IgraphicLib
{
public:
    virtual ~IgraphicLib(){};
    //SFML
    virtual void display() = 0; //display window
    virtual void initItem(std::string test, int x, int y, int w, int h) = 0;
    virtual void drawText(const std::string &_text, int x, int y, int size, int r, int g, int b) = 0;
 // implementer la fonction avec une liste ?
    virtual void initItem(std::vector <Element>) = 0;
    virtual void clear() = 0;
    virtual std::string getValue() = 0;
    virtual Input handleKey() = 0;
};
typedef IgraphicLib *(*maker_graph)();
#endif /* !GRAPHICLIB_HPP_ */
