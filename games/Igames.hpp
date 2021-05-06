/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Igames
*/


//interface de jeu
#ifndef IGAMES_HPP_
#define IGAMES_HPP_
#include "../include/helper.hpp"
#include "../include/IgraphicLib.hpp"

class Igames {
    public:
        virtual ~Igames(){};
        //fonction pour interagir avec l affichage

        virtual void update(std::vector<Element>) = 0;
        virtual void checkEvent(Input) = 0;
        virtual std::vector<Element> getAllElement() = 0;
        // virtual void displayAll() = 0;
        //draw

        //win or loose
        virtual void gameWin() = 0;
        virtual int gameLoose() = 0;


    protected:
    private:
};

typedef Igames *(*maker_game)();
#endif /* !IGAMES_HPP_ */
