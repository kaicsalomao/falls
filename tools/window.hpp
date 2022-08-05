#pragma once

#include "tools.hpp"
#include <SDL2/SDL.h>
using namespace std;

class Window
{
    public:
        Window(int width, int height, string title);
        ~Window();

        SDL_Renderer* getRenderer();
        SDL_Window* getWindow();

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};