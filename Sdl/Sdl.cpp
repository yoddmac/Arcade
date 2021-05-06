/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** sdl
*/

#include "ISdl.hpp"

extern "C"
{
    IgraphicLib* loadGraphicLib() {
        return (new Sdl());
    }
}

Sdl::Sdl()
{
    SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(1200, 800, 32, &window, &renderer);
    TTF_Init();
    this->font = TTF_OpenFont("./sfml/font/font.ttf", 15);
    if (!this->font) 
    {
        throw("erreur dans le chargement de font");
    }
}

Sdl::~Sdl()
{
    TTF_Quit();
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void Sdl::drawText(const std::string &_text, int x, int y, int size, int r, int g, int b)
{
    (void)size;
    int text_width;
    int text_height;
    SDL_Rect rect;
    SDL_Color textColor = {(Uint8)r, (Uint8)g, (Uint8)b, 0};

    this->surface = TTF_RenderText_Solid(font, _text.c_str(), textColor);
    if (!surface)
        throw ("erreur chargement surface SDL");
    this->texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!this->texture)
        throw ("erreur chargement texture");
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect.x = x * 16;
    rect.y = y * 16;
    rect.w = text_width;
    rect.h = text_height;
    SDL_RenderCopy(this->renderer, this->texture, NULL, &rect);
    SDL_RenderPresent(renderer);
   // SDL_DestroyTexture(this->texture);
    return;
}

std::string Sdl::getValue()
{
    return (this->value);
}

void Sdl::display()
{
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            this->value = "close";
            SDL_Quit();
        }
    }
 //   SDL_RenderPresent(this->renderer);
    return;
}

void Sdl::clear()
{
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
//    SDL_RenderPresent(this->renderer);
	SDL_RenderClear(this->renderer);
    return;
}

void Sdl::initItem(std::string test, int x, int y, int width, int height)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    SDL_Surface *sprite = IMG_Load(test.c_str());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(this->renderer, sprite);
    SDL_RenderCopy(this->renderer, texture, NULL, &rect);
  //  SDL_RenderPresent(this->renderer);
    //SDL_BlitSurface(sprite, NULL, SDL_GetWindowSurface(window), &rect);
   // SDL_DestroyTexture(this->texture);
    //SDL_FreeSurface(sprite);
}

void Sdl::initItem(std::vector <Element> v_element)
{
    for (const auto &vE : v_element) {
        std::string path = vE.path;
        SDL_Rect rect;
        rect.x = vE.posx;
        rect.y = vE.posy;
        rect.w = vE.width;
        rect.h = vE.height;

        SDL_Surface *sprite = IMG_Load(path.c_str());
        SDL_Texture *texture = SDL_CreateTextureFromSurface(this->renderer, sprite);
        // if(texture == NULL)
        //     throw("SDL can't charge texture");
        SDL_RenderCopy(this->renderer, texture, NULL, &rect);
      //  SDL_RenderPresent(this->renderer);
        SDL_RenderClear(this->renderer);
//        SDL_BlitSurface(sprite, NULL, SDL_GetWindowSurface(window), &rect);
        //SDL_DestroyTexture(this->texture);
 //       SDL_FreeSurface(sprite);
    }
}

Input Sdl::handleKey()
{
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.scancode == SDL_SCANCODE_UP) {
            return(Up);
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_LEFT) {
            return(Left);
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
            return(Right);
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN) {
            return(Down);
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
            return(Quit);
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_Q) {
            return(Menue);
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
            return(Start);
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_1) {
            return(PreviousLib);
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_2) {
            return(NextLib);
        }
    }
    return(Null);
}