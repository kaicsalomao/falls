#pragma once

#include "tools.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class Window
{
    public:
        Window(int width, int height, string title);
        ~Window();

        // Getters
        SDL_Renderer* getRenderer();
        SDL_Window* getWindow();

    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
};