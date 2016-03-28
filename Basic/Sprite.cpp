#define GLEW_STATIC
#include "Sprite.h"
#include "Vertex.h"
#include "Auxiliar/ResourceManager.h"
#include <cstddef>


Sprite::Sprite(const char *texturePath, const float &x, const float &y, const float &width, const float &height) :
    m_texture(ResourceManager::getTexture(texturePath)), m_x(x), m_y(y), m_width(width), m_height(height)
{
    glGenBuffers(1, &m_vboID);

    Vertex vertexData[6];

    //First triangle
    vertexData[0].setPosition(x + width, y + height);
    vertexData[0].setUV(1.0f, 1.0f);
    vertexData[1].setPosition(x, y + height);
    vertexData[1].setUV(0.0f, 1.0f);
    vertexData[2].setPosition(x, y);
    vertexData[2].setUV(0.0f, 0.0f);
    //Second triangle
    vertexData[3].setPosition(x, y);
    vertexData[3].setUV(0.0f, 0.0f);
    vertexData[4].setPosition(x + width, y);
    vertexData[4].setUV(1.0f, 0.0f);
    vertexData[5].setPosition(x + width, y + height);
    vertexData[5].setUV(1.0f, 1.0f);

    for (int i = 0; i < 6; ++i)
        vertexData[i].setColor(255, 0, 255, 255);

    //Top left corner
    vertexData[1].setColor(0, 0, 255, 255);
    //Bottom right corner
    vertexData[4].setColor(0, 255, 0, 255);

    glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Sprite::~Sprite()
{
    glDeleteBuffers(1, &m_vboID);
}

void Sprite::draw()
{
    glBindTexture(GL_TEXTURE_2D, m_texture.id);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboID);

    glEnableVertexAttribArray(0);

    //This is the position attribute pointer
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    //This is the color attribute pointer
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    //This is the UV attribute pointer
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

