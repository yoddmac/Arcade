/*
** EPITECH PROJECT, 2021
** OOP
** File description:
** arcade
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

#include <iostream>
#include <filesystem>
#include <string.h>
#include <dlfcn.h>
#include <algorithm>
#include <vector>
#include <fstream>
#include "../include/IgraphicLib.hpp"
#include "../include/encapsulation_dll.hpp"
#include "../games/Igames.hpp"

class Arcade {
    public:
    Arcade();
    ~Arcade();
    void initArcade(char* file);
    void find_lib();
    void make_highscore();
    void launch();
    int getIndexlib(std::vector<std::string> lib_list, char*);
    void lib_display_menu();

    void load_graphic_lb(int index);
    void load_game_lb(int index);


    //liste des libs
    std::vector<std::string> lib_list;
    std::vector<std::string> lib_game;
    char* defaultGame = strdup("lib/arcade_nibbler.so");
    //encapsulation
    std::unique_ptr<Encap_dl> _graphic;
    std::unique_ptr<Encap_dl> _game;

    std::string arcade_user = "default";
    std::string arcade_hs = "0";
    maker_graph graphicLib;
    maker_game gameLib;

    int graph_id = 0;
    int game_id = 0;

    void *hl;
    void *lib;
    IgraphicLib *my_lib;
    Igames *my_game;
    bool isLaunched = true;
    int step = 0;
    Element foo;
    Element bar;
    std::vector <Element> v_element;
};

#endif /* !ARCADE_HPP_ */
