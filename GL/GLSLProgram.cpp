#define GLEW_STATIC
#include "GLSLProgram.h"
#include "Auxiliar/Errors.h"
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>

GLSLProgram::GLSLProgram() :
    m_programID(glCreateProgram()), m_vertexShaderID(glCreateShader(GL_VERTEX_SHADER)), m_fragmentShaderID(glCreateShader(GL_FRAGMENT_SHADER)), m_numberAtrributes(0)
{}

GLSLProgram::~GLSLProgram()
{

}

void GLSLProgram::compileShaders(const char *vertexShaderPath, const char *fragmentShaderPath)
{
    if (!m_vertexShaderID)
        fatalError("Failed to create vertex shader...");
    if (!m_fragmentShaderID)
        fatalError("Failed to create fragment shader...");

    m_compileShader(vertexShaderPath, m_vertexShaderID);
    m_compileShader(fragmentShaderPath, m_fragmentShaderID);
}

void GLSLProgram::linkShaders()
{
    if (!m_programID)
        fatalError("Failed to create shader program...");

    glAttachShader(m_programID, m_vertexShaderID);
    glAttachShader(m_programID, m_fragmentShaderID);

    glLinkProgram(m_programID);

    GLint isLinked = 0;
    glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &isLinked);
    if (!isLinked)
    {
        GLint maxLength = 0;
        glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &maxLength);
        //The maxLength includes de NULL character
        std::vector<GLchar> errorLog(maxLength);
        glGetShaderInfoLog(m_programID, maxLength, &maxLength, &errorLog[0]);

        glDeleteProgram(m_programID);
        glDeleteShader(m_vertexShaderID);
        glDeleteShader(m_fragmentShaderID);
        printf("%s\n", &errorLog[0]);
        fatalError("Failed to link shaders to program...");
    }

    glDetachShader(m_programID, m_vertexShaderID);
    glDetachShader(m_programID, m_fragmentShaderID);
    glDeleteShader(m_vertexShaderID);
    glDeleteShader(m_fragmentShaderID);
}

void GLSLProgram::addAttribute(const char *attributeName)
{
    glBindAttribLocation(m_programID, m_numberAtrributes++, attributeName);
}

GLint GLSLProgram::getUniformLocation(const char *uniformName)
{
    GLint location = glGetUniformLocation(m_programID, uniformName);
    if (location == GL_INVALID_INDEX)
        fatalError("Uniform not found in shader: " + *uniformName);

    return location;
}

void GLSLProgram::use()
{
    glUseProgram(m_programID);
    for (int i = 0; i < m_numberAtrributes; ++i)
        glEnableVertexAttribArray(i);
}

void GLSLProgram::unuse()
{
    glUseProgram(0);
    for (int i = 0; i < m_numberAtrributes; ++i)
        glDisableVertexAttribArray(i);
}

void GLSLProgram::m_compileShader(const char *shaderPath, const GLuint &shaderID)
{
    std::ifstream shaderFile(shaderPath);
    if (shaderFile.fail())
    {
        perror(shaderPath);
        fatalError("Failed to open " + *shaderPath);
    }

    std::string fileContents("");
    std::string line;

    while (std::getline(shaderFile, line))
        fileContents += line + '\n';

    shaderFile.close();
    const char *contents = fileContents.c_str();
    glShaderSource(shaderID, 1, &contents, nullptr);
    glCompileShader(shaderID);
    GLint success = 0;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        GLint maxLength = 0;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);
        //The maxLength includes de NULL character
        std::vector<GLchar> errorLog(maxLength);
        glGetShaderInfoLog(shaderID, maxLength, &maxLength, &errorLog[0]);
        glDeleteShader(shaderID);
        printf("%s\n", &errorLog[0]);
        fatalError("Failed to link shaders...");
    }
}

