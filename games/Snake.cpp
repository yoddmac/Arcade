/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCY-4-1-arcade-hugo.zaneguy
** File description:
** Snake
*/

#include "Snake.hpp"

extern "C"
{
    Igames *loadGameLib()
    {
        return (new Snake());
    }
}

Snake::Snake()
{
    CreateSnakeList();
    CreateWallList();
    CreateApple("./Games/asset/apple.png", 200, 200);
}

Snake::~Snake()
{

}

void Snake::update(std::vector<Element>)
{
    this->vE.clear();
    for (auto &elem : this->list_snake)
        this->vE.push_back(elem);
    for (auto &elem : this->list_wall)
        this->vE.push_back(elem);
    this->vE.push_back(this->apple);
}

std::vector<Element> Snake::getAllElement()
{
    return (this->vE);
}

void Snake::CreateWallList()
{
    for (int y = 50; y <= 720; y += 65) {
        this->list_wall.push_back(CreateWallElement("./Games/asset/buisson_horizontal.png",0, y));
        this->list_wall.push_back(CreateWallElement("./Games/asset/buisson_horizontal.png",1130, y));
    }
    for (int x = 0; x <= 1130; x += 65) {
        this->list_wall.push_back(CreateWallElement("./Games/asset/buisson.png",x, 50));
        this->list_wall.push_back(CreateWallElement("./Games/asset/buisson.png",x, 720));
    }
}

void Snake::CreateSnakeList()
{
    for (int x = 200; x <= 392; x += 96)
        this->list_snake.push_back(CreateSnakeElement("./Games/asset/cercle.png", x, 100));
}

void Snake::CreateGameOver(std::string path, int x, int y)
{
    this->gameOver = {path, "GameOver", x, y, 10, 10};
}

Element Snake::CreateSnakeElement(std::string path, int x, int y)
{
    this->snake = {path, "X", x, y, 10, 10};

    return this->snake;
}

void Snake::CreateApple(std::string path, int x, int y)
{
    this->apple = {path, "O", x, y, 10, 10};
}

Element Snake::CreateWallElement(std::string path, int x, int y)
{
    this->wall = {path, "#", x, y, 10, 10};
    return this->wall;
}
void Snake::EatApple()
{
    srand(time(NULL));
    int posApplex = this->apple.posx;
    int posAppley = this->apple.posy;

    int posCircelx = this->list_snake[0].posx;
    int posCircely = this->list_snake[0].posy;

    int randx = rand() % 650 + 50;
    int randy = rand() % 450 + 50;

    if ((posCircelx + 96 >= posApplex && posCircelx <= posApplex + 96) && (posCircely + 96 >= posAppley && posCircely <= posAppley + 96))
    {
        while (randx == posCircelx || randy == posCircely)
        {
            randx = rand() % 650 + 50;
            randy = rand() % 450 + 50;
        }
        this->apple.posx = randx;
        this->apple.posy = randy;
        this->list_snake.push_back(CreateSnakeElement("./Games/asset/cercle.png", posCircelx, posCircely));
    }
}

void Snake::checkEvent(Input k)
{
    int x = this->list_snake[0].posx;
    int y = this->list_snake[0].posy;
    bool move = false;

    if (k == Input::Up)
    {
        y -= 15;
        move = true;
    }
    else if (k == Input::Left)
    {
        x -= 15;
        move = true;
    }
    else if (k == Input::Right)
    {
        x += 15;
        move = true;
    }
    else if (k == Input::Down)
    {
        y += 15;
        move = true;
    }
    this->list_snake[0].posx = x;
    this->list_snake[0].posy = y;

    if (move)
        BodyFollow();

    EatApple();
    gameLoose();
    this->update(this->vE);
}

void Snake::BodyFollow()
{
    std::vector<Element>::iterator first_it;
    std::vector<Element>::iterator second_it;
    std::vector<Element> tmpMap = this->list_snake;
    std::vector<Element> tmpMapBis = this->list_snake;
    int i = 0;

    for (first_it = std::next(this->list_snake.begin()); first_it != this->list_snake.end(); first_it++)
    {
        for (second_it = std::next(this->list_snake.begin()); second_it != this->list_snake.end(); second_it++)
        {
            second_it->posx = tmpMap[i].posx;
            second_it->posy = tmpMap[i].posy;
            i++;
        }
        i = 0;
        tmpMap = tmpMapBis;
    }
}

int Snake::gameLoose()
{
    int firstSnakeX = this->list_snake[0].posx;
    int firstSnakeY = this->list_snake[0].posy;

    if (firstSnakeY >= 800 || firstSnakeY <= 50 || firstSnakeX >= 1200 || firstSnakeX <= 0) {
        return(1);
    }
    return 0;
}
