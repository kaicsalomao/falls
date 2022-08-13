#include "../engine/vector2.hpp"

Vector2::Vector2(int x, int y)
{
    this->x = x;
    this->y = y;
}

Vector2::~Vector2()
{}

// Getters
int Vector2::getX()
{
    return x;
}
int Vector2::getY()
{
    return y;
}

// Setters
void Vector2::setX(int x)
{
    this->x = x;
}
void Vector2::setY(int y)
{
    this->y = y;
}

// Operators
Vector2 Vector2::operator+(Vector2 v)
{
    Vector2 result(x + v.getX(), y + v.getY());
    return result;
}
Vector2 Vector2::operator-(Vector2 v)
{
    Vector2 result(x - v.getX(), y - v.getY());
    return result;
}
Vector2 Vector2::operator*(int n)
{
    Vector2 result(x * n, y * n);
    return result;
}
Vector2 Vector2::operator/(int n)
{
    Vector2 result(x / n, y / n);
    return result;
}
