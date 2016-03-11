#ifndef STATEBASE_H
#define STATEBASE_H

struct GLFWwindow;

class StateBase
{
public:
    virtual void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) = 0;
    virtual void window_close_callback(GLFWwindow* window) = 0;
    virtual void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) = 0;
    static StateBase *event_handling_instance;
    // technically setEventHandling should be finalized so that it doesn't
    // get overwritten by a descendant class.
    virtual void setEventHandling() { event_handling_instance = this; }

    static void key_callback_dispatch(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        if(event_handling_instance)
            event_handling_instance->key_callback(window,key,scancode,action,mods);
    }
    static void window_close_callback_dispatch(GLFWwindow *window)
    {
        if(event_handling_instance)
            event_handling_instance->window_close_callback(window);
    }

    static void cursor_position_callback_dispatch(GLFWwindow* window, double xpos, double ypos)
    {
        if(event_handling_instance)
            event_handling_instance->cursor_position_callback(window, xpos, ypos);
    }

};

#endif // STATEBASE_H
