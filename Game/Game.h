#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "StateBase.h"

class Sprite;
class GLSLProgram;

enum GameState
{
    PLAY,
    EXIT
};

class Game : public StateBase
{
public:
    Game();
    ~Game();

    void run();
    static GLushort ScreenWidth;
    static GLushort ScreenHeight;

private:
    GLFWwindow *m_window;
    GameState m_currentGameState;
    Sprite *m_tmpSprite;
    GLSLProgram *m_colorProgram;
    float m_time;

    void m_initSystems();
    void m_initShaders();
    void m_loop();
    void m_processInput();
    void m_draw();
    void key_callback(GLFWwindow * /*window*/, int key, int /*scancode*/, int action, int /*mods*/);
    void window_close_callback(GLFWwindow * /*window*/);
    void cursor_position_callback(GLFWwindow * /*window*/, double xpos, double ypos);
};

#endif // GAME_H
