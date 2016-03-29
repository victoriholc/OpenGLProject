TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

win32:
{
#    LIBS += -L"E:/GLFW/glfw-3.1.2.bin.WIN64/lib-vc2013" -lglfw3dll /NODEFAULTLIB:glfw3dll
#    LIBS += -L"E:/GLFW/glfw-3.1.2.bin.WIN64/lib-vc2013" -lopengl32 /NODEFAULTLIB:opengl32
#    LIBS += -L"E:/GLFW/glfw-3.1.2.bin.WIN64/lib-vc2013" -lglu32 /NODEFAULTLIB:glu32
#    LIBS += -L"E:/GLFW/glfw-3.1.2.bin.WIN64/lib-vc2013" -luser32 /NODEFAULTLIB:user32
#    LIBS += -L"E:/GLFW/glfw-3.1.2.bin.WIN64/lib-vc2013" -lgdi32 /NODEFAULTLIB:gdi32
#    LIBS += -L"E:/GLFW/glew-1.13.0/lib/Release/x64" -lglew32s /NODEFAULTLIB:glew32s

#    INCLUDEPATH += "E:/GLFW/glfw-3.1.2.bin.WIN64/include/"
#    INCLUDEPATH += "E:/GLFW/glew-1.13.0/include"

    LIBS += -L"C:/GLFW/glfw-3.1.2.bin.WIN64/lib-vc2013" -lglfw3dll /NODEFAULTLIB:glfw3dll
    LIBS += -L"C:/GLFW/glfw-3.1.2.bin.WIN64/lib-vc2013" -lopengl32 /NODEFAULTLIB:opengl32
    LIBS += -L"C:/GLFW/glfw-3.1.2.bin.WIN64/lib-vc2013" -lglu32 /NODEFAULTLIB:glu32
    LIBS += -L"C:/GLFW/glfw-3.1.2.bin.WIN64/lib-vc2013" -luser32 /NODEFAULTLIB:user32
    LIBS += -L"C:/GLFW/glfw-3.1.2.bin.WIN64/lib-vc2013" -lgdi32 /NODEFAULTLIB:gdi32
    LIBS += -L"C:/GLFW/glew-1.13.0/lib/Release/x64" -lglew32s /NODEFAULTLIB:glew32s

    INCLUDEPATH += "C:/GLFW/glfw-3.1.2.bin.WIN64/include/"
    INCLUDEPATH += "C:/GLFW/glew-1.13.0/include"
}

HEADERS += \
    Game/Game.h \
    Basic/StateBase.h \
    Basic/Sprite.h \
    Basic/Vertex.h \
    GL/GLTexture.h \
    GL/GLSLProgram.h \
    Auxiliar/Errors.h \
    Auxiliar/IOManager.h \
    Auxiliar/ImageLoader.h \
    Auxiliar/PicoPNG.h \
    Auxiliar/Paths.h \
    Auxiliar/ResourceManager.h \
    Cache/TextureCache.h

SOURCES += main.cpp \
    Game/Game.cpp \
    Basic/StateBase.cpp \
    Basic/Sprite.cpp \
    GL/GLSLProgram.cpp \
    Auxiliar/Errors.cpp \
    Auxiliar/IOManager.cpp \
    Auxiliar/PicoPNG.cpp \
    Auxiliar/ImageLoader.cpp \
    Auxiliar/ResourceManager.cpp \
    Cache/TextureCache.cpp
