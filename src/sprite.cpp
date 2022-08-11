#include "../engine/sprite.hpp"

Sprite::Sprite(SDL_Renderer* renderer)
{
    i_renderer = renderer;
}
Sprite::~Sprite()
{}

SDL_Texture* Sprite::loadTexture(string path)
{
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(i_renderer, path.c_str());

    if ( texture == NULL )
        cout << "Falha ao carregar a textura: " << SDL_GetError() << endl;
    
    SDL_QueryTexture(texture, NULL, NULL, &texture_width, &texture_height);
    return texture;
}
void Sprite::renderTexture(SDL_Texture* texture, float pos_x, float pos_y)
{
    SDL_Rect dstRect; // Destination rect
    dstRect.x = pos_x;
    dstRect.y = pos_y;
    dstRect.w = texture_width;
    dstRect.h = texture_height;

    SDL_RenderCopy(i_renderer, texture, NULL, &dstRect);
}
void Sprite::renderTexture(SDL_Texture* texture, float pos_x, float pos_y, int w, int h)
{
    SDL_Rect dstRect; // Destination rect
    dstRect.x = pos_x;
    dstRect.y = pos_y;
    dstRect.w = w;
    dstRect.h = h;

    SDL_RenderCopy(i_renderer, texture, NULL, &dstRect);
}

void Sprite::renderTexture(SDL_Texture* texture, float pos_x, float pos_y, int w, int h, int frame)
{
    SDL_Rect dstRect; // Destination rect
    dstRect.x = pos_x;
    dstRect.y = pos_y;
    dstRect.w = w;
    dstRect.h = h;

    SDL_Rect srcRect; // Source rect
    srcRect.x = frame * w;
    srcRect.y = 0;
    srcRect.w = w;
    srcRect.h = h;

    SDL_RenderCopy(i_renderer, texture, &srcRect, &dstRect);
}