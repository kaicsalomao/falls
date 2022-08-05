#include "../tools/tools.hpp"
#include "../tools/window.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

// Variables and others
#define GAME_WIDTH 640
#define GAME_HEIGHT 480

Window window(GAME_WIDTH, GAME_HEIGHT, "Falls");

SDL_Event event;
bool game_running = false;
// Game functions
void init()
{
    game_running = true;

    // Init SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    // Background color
    SDL_SetRenderDrawColor(window.getRenderer(), 0, 255, 0, 255);
}

void update()
{
    while (game_running)
    {
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    game_running = false;
                    break;
            }
        }

        SDL_RenderClear(window.getRenderer());
        SDL_RenderPresent(window.getRenderer());
    }
}

void finish()
{
    game_running = false;

    window.~Window();
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char** argv)
{
    cout << "---------- START ----------" << endl;

    // Call functions
    init();
    update();
    finish();

    return 0;
}