#include "../engine/window.hpp"

Window::Window(int width, int height, string title)
{
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
}
Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

// Getters
SDL_Renderer* Window::getRenderer()
{
    return renderer;
}
SDL_Window* Window::getWindow()
{
    return window;
}