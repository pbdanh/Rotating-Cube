#include "face.hpp"
#include <iostream>

_3DPoint rotation(_3DPoint point)
{
	_3DPoint point_;
	point_.x = point.x * std::cos(A) + point.z * std::sin(A);
	point_.y = (2 * point.y * std::cos(B) - point.x * std::cos(A + B) + point.x * std::cos(A - B) - point.z * std::sin(A + B) + point.z * std::sin(A - B)) / 2;
	point_.z = (point.z * std::cos(A + B) + point.z * std::cos(A - B) + 2 * point.y * std::sin(B) - point.x * std::sin(A + B) - point.x * std::sin(A - B)) / 2;
	float k = (viewerCoordinate - screenCoordinate) / (viewerCoordinate - point_.z);
	point_.x = point_.x * k + X0;
	point_.y = point_.y * k + Y0;
	return point_;
}

void Face::set(_3DPoint point1, _3DPoint point2, SDL_Color _color)
{
    startPoint = point1;
    endPoint = point2;
    color = _color;
}

void Face::render() {
    for(int x = std::min(startPoint.x, endPoint.x); x <= std::max(startPoint.x, endPoint.x); x++)
        for(int y = std::min(startPoint.y, endPoint.y); y <= std::max(startPoint.y, endPoint.y); y++)
            for(int z = std::min(startPoint.z, endPoint.z); z <= std::max(startPoint.z, endPoint.z); z++)
            {
                _3DPoint point = {x, y, z};
                point = rotation(point);
                if(screenPixels[(int)point.x][(int)point.y].first < point.z)
                {
                    screenPixels[(int)point.x][(int)point.y].first = point.z;
                    screenPixels[(int)point.x][(int)point.y].second = color;
                }
            }
}