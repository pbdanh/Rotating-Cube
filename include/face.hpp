#pragma once

#include "common.hpp"
#include "3dPoint.hpp"
#include <cmath>
#include <algorithm>

extern float A;
extern float B;
extern std::pair <float, SDL_Color> screenPixels[600][400];

class Face
{
private:
    _3DPoint startPoint;
    _3DPoint endPoint;
    SDL_Color color;
public:
    Face(){};
    ~Face(){};
    void set(_3DPoint point1, _3DPoint point2, SDL_Color _color);
    void render();
};