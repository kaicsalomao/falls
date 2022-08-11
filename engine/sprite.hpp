#pragma once

#include "tools.hpp"
#include "window.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class Sprite
{
    public:
        Sprite(SDL_Renderer* renderer);
        ~Sprite();

        SDL_Texture* loadTexture(string path);
        void renderTexture(SDL_Texture* texture, float pos_x, float pos_y); // Normal image size
        void renderTexture(SDL_Texture* texture, float pos_x, float pos_y, int w, int h); // Resize the image

        // Animation sprites
        void renderTexture(SDL_Texture* texture, float pos_x, float pos_y, int w, int h, int frame); // Resize the image
        
    private:
        SDL_Renderer* i_renderer; // Internal renderer
        int texture_width, texture_height;
};