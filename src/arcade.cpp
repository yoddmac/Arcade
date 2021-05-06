/*
** EPITECH PROJECT, 2021
** OOP
** File description:
** arcade
*/

#include "arcade.hpp"

Arcade::Arcade() {
}

Arcade::~Arcade() {}

void Arcade::initArcade(char *file)
{
    find_lib();
    this->graph_id = getIndexlib(this->lib_list, file);
    this->game_id = getIndexlib(this->lib_game, this->defaultGame);
    make_highscore();
    load_graphic_lb(this->graph_id);
    load_game_lb(this->game_id);
    launch();
}

int Arcade::getIndexlib(std::vector<std::string> lib_list, char* file)
{
    auto it = find(lib_list.begin(), lib_list.end(), "./"+std::string(file));
    if (it != lib_list.end())
        return (it - lib_list.begin());
}

void Arcade::load_graphic_lb(int index)
{
    if (index < 0 || index > (int)this->lib_list.size())
        throw ("no more graphic library");
    this->_graphic = std::make_unique<Encap_dl>(this->lib_list[index].c_str());
    this->graphicLib = maker_graph(this->_graphic->getDlsym("loadGraphicLib"));
    this->my_lib = this->graphicLib();
}

void Arcade::load_game_lb(int index)
{
    if (index < 0 || index > (int)this->lib_game.size())
        throw ("no more game library");
    this->_game = std::make_unique<Encap_dl>(this->lib_game[index].c_str());
    this->gameLib = maker_game(this->_game->getDlsym("loadGameLib"));
    this->my_game = this->gameLib();
}

void Arcade::find_lib()
{
    namespace fs = std::filesystem;

    for (auto& p: fs::directory_iterator("lib")) {
        if (p.path().string().find("so") != std::string::npos) {
            auto ptr = std::make_unique<Encap_dl>(p.path().string().c_str());
            if (ptr->getDlsym("loadGraphicLib") != NULL)
                lib_list.push_back("./" + p.path().string());
            else if (ptr->getDlsym("loadGameLib") != NULL)
                lib_game.push_back("./" + p.path().string());
        }
    }
}

void Arcade::make_highscore()
{
    std::ifstream  file("highscore.txt");
    std::string line;
// si le fichier existe et qu'il n'est pas vide recup info player et stock
    bool empty = file.peek() == EOF;
    if (file.is_open() && !empty) {     
        std::cout << "Enter the player Name" << std::endl;
        std::cin >> arcade_user;
        while (std::getline(file, line)) {
            size_t sep = -1;
            sep = line.find(':');
            arcade_hs = line.substr(sep+1);
        }
        std::ofstream  file("highscore.txt");
        file << arcade_user << ":" << arcade_hs <<std::endl;
    }
    //si le fichier est vide ou que le score sera plus grand que celui lu
    else {
        std::ofstream  file("highscore.txt");
        if (file.is_open()) {
            std::cout << "Enter the player Name" << std::endl;
            std::cin >> arcade_user;
            file << arcade_user << ":" << arcade_hs << ";" << std::endl;
        }
    }
    file.close();
}

void Arcade::lib_display_menu()
{
    int y = 20;
    my_lib->drawText("Username:", 30, 10, 20, 0, 255 , 0);
    my_lib->drawText(this->arcade_user, 40, 10, 20, 255, 255 , 255);
    my_lib->drawText("HighScore:", 30, 12, 20, 0, 255 , 0);
    my_lib->drawText(this->arcade_hs, 40, 12, 20, 255, 255 , 255);
    my_lib->drawText("Graphic Library:", 30, 17, 20, 0, 255 , 0);
    for (auto const& i : this->lib_list) {
        my_lib->drawText(i, 30, y, 20, 255, 255 , 255);
        y += 3;
    }
    my_lib->drawText("Press ESC for quit Arcade", 30, 40, 20, 255, 0 , 0);
}

void Arcade::launch()
{
    while(isLaunched && step == 0)
    {
        my_lib->clear();
        lib_display_menu();
        my_lib->display();
        if (my_lib->handleKey() == Input::PreviousLib) {
            graph_id -= 1;
            delete this->my_lib;
            load_graphic_lb(this->graph_id);
        }
        if (my_lib->handleKey() == Input::NextLib){
            graph_id +=1;
            delete this->my_lib;
            load_graphic_lb(this->graph_id);
        }
        if (my_lib->handleKey() == Input::Start) {
            step = 1;
            my_lib->clear();
        }
        if (my_lib->handleKey() == Input::Quit || my_lib->getValue() == "close")
            break;
    }
    while(isLaunched && step == 1) {
        my_lib->clear();

        auto el = my_game->getAllElement();
        my_game->update(el);
        my_lib->initItem(el);
        auto k = my_lib->handleKey();
        my_game->checkEvent(k);
        my_lib->display();
        if (my_lib->handleKey() == Input::PreviousLib) {
            graph_id -= 1;
            delete this->my_lib;
            load_graphic_lb(this->graph_id);
        }
        if (my_lib->handleKey() == Input::NextLib){
            graph_id +=1;
            delete this->my_lib;
            load_graphic_lb(this->graph_id);
        }
        if (my_lib->handleKey() == Input::Quit || my_lib->getValue() == "close")
            break;
    }

}