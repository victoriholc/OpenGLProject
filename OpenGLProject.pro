TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

win32:
{
    LIBS += -L"E:/GLFW/glfw-3.1.2.bin.WIN64/lib-vc2013" -lglfw3dll /NODEFAULTLIB:glfw3dll
    LIBS += -L"E:/GLFW/glfw-3.1.2.bin.WIN64/lib-vc2013" -lopengl32 /NODEFAULTLIB:opengl32
    LIBS += -L"E:/GLFW/glfw-3.1.2.bin.WIN64/lib-vc2013" -lglu32 /NODEFAULTLIB:glu32
    LIBS += -L"E:/GLFW/glfw-3.1.2.bin.WIN64/lib-vc2013" -luser32 /NODEFAULTLIB:user32
    LIBS += -L"E:/GLFW/glfw-3.1.2.bin.WIN64/lib-vc2013" -lgdi32 /NODEFAULTLIB:gdi32
    LIBS += -L"E:/GLFW/glew-1.13.0/lib/Release/x64" -lglew32s /NODEFAULTLIB:glew32s

    INCLUDEPATH += "E:/GLFW/glfw-3.1.2.bin.WIN64/include/"
    INCLUDEPATH += "E:/GLFW/glew-1.13.0/include"
}

HEADERS += \
    Game/Game.h \
    Game/StateBase.h \
    Game/Sprite.h \
    Game/GLSLProgram.h \
    Game/Errors.h \
    Game/Vertex.h \
    Game/IOManager.h \
    Game/PicoPNG.h \
    Game/GLTexture.h \
    Game/ImageLoader.h

SOURCES += main.cpp \
    Game/Game.cpp \
    Game/StateBase.cpp \
    Game/Sprite.cpp \
    Game/GLSLProgram.cpp \
    Game/Errors.cpp \
    Game/IOManager.cpp \
    Game/PicoPNG.cpp \
    Game/ImageLoader.cpp
