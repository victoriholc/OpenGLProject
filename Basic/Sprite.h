#ifndef SPRITE_H
#define SPRITE_H

#include <GL/glew.h>

class Sprite
{
public:
    Sprite(const float &x, const float &y, const float &width, const float &height);
    ~Sprite();

    void draw();
private:
    float m_x;
    float m_y;
    float m_width;
    float m_height;

    GLuint m_vboID;
};

#endif // SPRITE_H
