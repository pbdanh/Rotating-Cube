#include "face.hpp"

class Cube
{
private:
    Face faces[6];
public:
    Cube();
    ~Cube() {};
    void render();
};