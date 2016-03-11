#define GLEW_STATIC
#include "Game.h"
#include "Errors.h"
#include "GLSLProgram.h"
#include "Sprite.h"
#include <stdio.h>
#include <iostream>

GLushort Game::ScreenWidth = 800;
GLushort Game::ScreenHeight = 600;

Game::Game() :
    m_window(nullptr), m_currentGameState(GameState::PLAY),
    m_tmpSprite(nullptr), m_colorProgram(nullptr), m_time(0.0f)
{}

Game::~Game()
{
    delete m_tmpSprite;
    delete m_colorProgram;
    glfwSetWindowShouldClose(m_window, GL_TRUE);
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Game::run()
{
    m_initSystems();
    m_tmpSprite = new Sprite(-1.0f, -1.0f, 2.0f, 2.0f);
    m_tmpSprite->draw();
    m_loop();
}

void Game::m_initSystems()
{
    glfwInit();

//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    m_window = glfwCreateWindow(ScreenWidth, ScreenHeight, "Game Engine", nullptr, nullptr);
    if (!m_window)
        fatalError("Could not create a window...");
//    GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), nullptr);
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *vidmode = glfwGetVideoMode(monitor);
    glfwSetWindowPos(m_window, (vidmode->width - ScreenWidth) / 2, (vidmode->height - ScreenHeight) / 2);

    glfwMakeContextCurrent(m_window);
    StateBase::setEventHandling();
    glfwSetKeyCallback(m_window, StateBase::key_callback_dispatch);
    glfwSetWindowCloseCallback(m_window, StateBase::window_close_callback_dispatch);
    glfwSetCursorPosCallback(m_window, StateBase::cursor_position_callback_dispatch);
//    glewExperimental = true;
    if (glewInit() != GLEW_OK)
        fatalError("Could not initialize glew...");

    glClearColor(0.0f, 0.1f, 0.2f, 1.0f);
//    GLuint vertexBuffer;
//    glGenBuffers(1, &vertexBuffer);
//    printf("%u\n", vertexBuffer);
    m_initShaders();
}

void Game::m_initShaders()
{
    m_colorProgram = new GLSLProgram;
    m_colorProgram->compileShaders("E:/Projects/C++/GLFW/OpenGLProject/Shaders/colorShading.vert", "E:/Projects/C++/GLFW/OpenGLProject/Shaders/colorShading.frag");
    m_colorProgram->addAttribute("vertexPos");
    m_colorProgram->addAttribute("vertexColor");
    m_colorProgram->linkShaders();
}


void Game::m_loop()
{
    while (m_currentGameState != GameState::EXIT)
    {
        m_processInput();
        m_time += 0.001f;
        m_draw();
    }

//    while(!glfwWindowShouldClose(window))
//    {
//        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//            glfwSetWindowShouldClose(window, GL_TRUE);
//    }
}

void Game::m_processInput()
{
    glfwPollEvents();
}

void Game::m_draw()
{
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_colorProgram->use();

    GLint timeUniformLocation = m_colorProgram->getUniformLocation("time");
    glUniform1f(timeUniformLocation, m_time);

    m_tmpSprite->draw();

    m_colorProgram->unuse();

    glfwSwapBuffers(m_window);
}

void Game::key_callback(GLFWwindow * /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        m_currentGameState = GameState::EXIT;
}

void Game::window_close_callback(GLFWwindow * /*window*/)
{
//    if (!canClose)
    m_currentGameState = GameState::EXIT;
}

void Game::cursor_position_callback(GLFWwindow * /*window*/, double xpos, double ypos)
{
//    if (!canClose)
//    printf("Mouse x:%f Mouse y:%f\n", xpos, ypos);
}
