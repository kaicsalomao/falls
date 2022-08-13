#include "../engine/tools.hpp"
#include "../engine/sprite.hpp"
#include "../engine/window.hpp"
#include "../engine/vector2.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

// Variables and others
const int GAME_WIDTH = 840;
const int GAME_HEIGHT = 480;

Window window(GAME_WIDTH, GAME_HEIGHT, "Falls");
Sprite sprite(window.getRenderer());

Vector2 position(0, 0);

SDL_Event event;
bool game_running = false;

SDL_Texture* background = nullptr;
SDL_Texture* ground = nullptr;

// Game functions
void init()
{
    game_running = true;
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG || IMG_INIT_JPG);

    background = sprite.loadTexture("assets/bg.jpg");
    ground = sprite.loadTexture("assets/ground.png");
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

        // Clear screen
        SDL_RenderClear(window.getRenderer());

        sprite.renderTexture(background, 0, 0);
        sprite.renderTexture(ground, position.getX(), position.getY(), 100, 100);

        SDL_RenderPresent(window.getRenderer());
    }
}

void finish()
{
    game_running = false;

    window.~Window();
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(ground);
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