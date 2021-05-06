/*
** EPITECH PROJECT, 2021
** OOP
** File description:
** main
*/

#include <iostream>
#include <string.h>
#include "src/arcade.hpp"

int main(int ac, char **av)
{
    Arcade *arcade = new Arcade();
    if(ac == 1) {
        std::cerr << "Bad usage, you need to pass a graphic library" << std::endl;
        return 84;
    }
    try 
    {
        arcade->initArcade(av[1]);
    }
    catch (char const* &e)
    {
        std::cerr << e << std::endl;
        return 84;
    }
    return (0);
}