#include "cube.hpp"

Cube::Cube() {
    faces[0].set({-100, -100, -100}, {-100, 100, 100}, {255, 0, 0, 255});
    faces[1].set({-100, -100, -100}, {100, -100, 100}, {255, 255, 255, 255});
    faces[2].set({-100, -100, -100}, {100, 100, -100}, {0, 255, 0, 255});
    faces[3].set({-100, 100, 100}, {100, -100, 100}, {0, 0, 255, 255});
    faces[4].set({-100, 100, 100}, {100, 100, -100}, {255, 255, 0, 255});
    faces[5].set({100, -100, 100}, {100, 100, -100}, {255, 127, 0, 255});
}

void Cube::render() {
    for(int i = 0; i < 6; i++)
    {
        faces[i].render();
    }
}