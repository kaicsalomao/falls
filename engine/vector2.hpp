#pragma once

#include "tools.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

class Vector2
{
    public:
        Vector2(int x, int y);
        ~Vector2();

        // Getters
        int getX();
        int getY();

        // Setters
        void setX(int x);
        void setY(int y);

        // Operators
        Vector2 operator+(Vector2 v);
        Vector2 operator-(Vector2 v);
        Vector2 operator*(int n);
        Vector2 operator/(int n);

    private:
        int x;
        int y;
};