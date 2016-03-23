#version 130

in vec2 fragmentPos;
in vec4 fragmentColor;
in vec2 fragmentUV;

out vec2 position;
out vec4 color;

uniform float time;
uniform sampler2D textureSampler;

void main()
{
//    color = fragmentColor + vec4(1.0 * (cos(time) + 1.0) / 2,
//                                 1.0 * (cos(time + 2.0) + 1.0) / 2,
//                                 1.0 * (sin(time + 1.0) + 1.0) / 2,
//                                 0);
//    color = vec4(fragmentColor.r + (cos(fragmentPos.x + time) + 1.0) / 2,
//                 fragmentColor.g + (cos(fragmentPos.y + time) + 1.0) / 2,
//                 fragmentColor.b + (cos(fragmentPos.x * 0.4 + time) + 1.0) / 2,
//                 fragmentColor.a);

    vec3 textureColor = texture(textureSampler, fragmentUV);

    color = textureColor * fragmentColor;

//    color = vec4(fragmentColor.r + (cos(fragmentPos.x + time) + 1.0) / 2,
//                 fragmentColor.g + (cos(fragmentPos.y + time) + 1.0) / 2,
//                 fragmentColor.b + (cos(fragmentPos.x * 0.4 + time) + 1.0) / 2,
//                 fragmentColor.a);
}
