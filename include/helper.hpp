/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** helper
*/

#ifndef HELPER_HPP_
#define HELPER_HPP_

#include <string>
#include <iostream>
#include <vector>

struct Element {
    std::string path;
    const char *charactere;
    int posx;
    int posy;
    int width;
    int height;
};

enum Input {
    Up,
    Down,
    Right,
    Left,
    Quit,
    NextLib,
    PreviousLib,
    Start,
    Null,
    Menue
};

using v_element = std::vector<Element>;


#endif /* !HELPER_HPP_ */