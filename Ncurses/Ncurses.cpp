/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCY-4-1-arcade-hugo.zaneguy
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

extern "C"
{
IgraphicLib* loadGraphicLib() {
    return (new Ncurses());
}
}

Ncurses::Ncurses()
{
    _window = initscr();
    noecho();
    keypad(stdscr, TRUE);
}

Ncurses::~Ncurses()
{
    endwin();
}

void Ncurses::display()
{
    refresh();
    nodelay(this->_window, TRUE);
    hk = getch();
    if (hk == 27) {
        this->value = "close";
        endwin();
    }
}

void Ncurses::drawText(const std::string &_text, int x, int y, int size, int r, int g, int b)
{
    (void)r;
    (void)g;
    (void)b;
    (void)size;

    // auto resize = this->resizing(y, x, this->_window);
    // mvwprintw(this->_window, 40, 100, "Chose");
    mvwprintw(this->_window, y , x, _text.c_str());
}


std::pair<int, int> Ncurses::resizing (int y, int x, WINDOW *window)
{
    unsigned int posx = 0;
    unsigned int posy = 0;

    getmaxyx(this->_window, posy, posx);
    return std::make_pair((y/100) * posy, (x/100) * posx);
}

void Ncurses::initItem(std::vector <Element> v_element) {
    for (const auto &vE : v_element) {
        mvwprintw(this->_window, vE.posy /10, vE.posx/10, vE.charactere);
    }
};


Input Ncurses::handleKey() {
    if (hk == KEY_UP)
        return(Start);
    else if (hk == KEY_DOWN)
        return(Down);
    else if (hk == KEY_LEFT)
        return(Left);
    else if (hk == KEY_RIGHT)
        return (Right);
    else if (hk == 49)
        return (PreviousLib);
    else if (hk == 50)
        return (NextLib);
    else if (hk == 10)
        return(Start);
    else if (hk == 113)
        return(Menue);
    else if (hk == 27)
        return(Quit);
    return (Null);
}

void Ncurses::clear()
{
    werase(_window);
}

// int main()
// {
//     Ncurses *n = new Ncurses();
//    // n->drawText("bite",10, 10, 1,1,1,1);
//     // n->initItem("a", 10, 10, 0, 0);
//     // n->display();
// }