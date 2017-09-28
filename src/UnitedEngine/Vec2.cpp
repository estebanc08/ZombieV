#include "UnitedEngine/Vec2.h"
#include <cmath>

Vec2::Vec2() : x(0), y(0) {}

Vec2::Vec2(const Vec2& coord1, const Vec2& coord2)
{
    x = coord2.x-coord1.x;
    y = coord2.y-coord1.y;
}

Vec2::Vec2(float cx, float cy) : x(cx), y(cy)
{}

void Vec2::move2D(Vec2& vec)
{
    this->x += vec.x;
    this->y += vec.y;
}

float Vec2::getNorm() const
{
    return sqrt(x*x+y*y);
}

Vec2 operator/(const Vec2& c, float d)
{
    return Vec2(c.x/d, c.y/d);
}

Vec2 operator-(const Vec2& c1, const Vec2& c2)
{
    return Vec2(c1.x-c2.x, c1.y-c2.y);
}

Vec2 operator-(const Vec2& c1)
{
    return Vec2(-c1.x, -c1.y);
}

Vec2 operator*(const Vec2& c, float d)
{
    return Vec2(c.x*d, c.y*d);
}
Vec2 operator*(float d, Vec2 c)
{
    return Vec2(c.x*d, c.y*d);
}

Vec2 operator+(const Vec2 c1, const Vec2 c2)
{
    return Vec2(c1.x+c2.x, c1.y+c2.y);
}

Vec2 operator+(const Vec2& c1, const Vec2& c2)
{
    return Vec2(c1.x+c2.x, c1.y+c2.y);
}
