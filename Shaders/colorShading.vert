#version 130

in vec2 vertexPos;
in vec4 vertexColor;

out vec2 fragmentPos;
out vec4 fragmentColor;

void main()
{
    gl_Position.xy = vertexPos;
    gl_Position.z = 0.0;
    //Indicates that the coordinates are normalized
    gl_Position.w = 1.0;

    fragmentPos = vertexPos;
    fragmentColor = vertexColor;
}
