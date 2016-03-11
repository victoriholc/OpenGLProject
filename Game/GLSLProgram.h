#ifndef GLSLPROGRAM_H
#define GLSLPROGRAM_H

#include <gl/glew.h>

class GLSLProgram
{
public:
    GLSLProgram();
    ~GLSLProgram();

    void compileShaders(const char *vertexShaderPath, const char *fragmentShaderPath);
    void linkShaders();
    void addAttribute(const char *attributeName);
    GLint getUniformLocation(const char *uniformName);

    void use();
    void unuse();
private:
    GLuint m_programID;
    GLuint m_vertexShaderID;
    GLuint m_fragmentShaderID;
    int m_numberAtrributes;

    void m_compileShader(const char *shaderPath, const GLuint &shaderID);
};

#endif // GLSLPROGRAM_H
