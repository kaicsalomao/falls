#include "../engine/tools.hpp"
#include "../engine/sprite.hpp"
#include "../engine/window.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

// Variables and others
#define GAME_WIDTH 640
#define GAME_HEIGHT 480

Window window(GAME_WIDTH, GAME_HEIGHT, "Falls");
Sprite sprite(window.getRenderer());

SDL_Event event;
bool game_running = false;
double pos_x, pos_y;
double lastTime = 0;

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
        sprite.renderTexture(ground, pos_x, 100, 100, 100);
        
        // Time
        double currentTime = SDL_GetTicks();
        double deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // Update
        pos_x += deltaTime / 1000;
        if (pos_x > GAME_WIDTH)
            pos_x = 0;

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