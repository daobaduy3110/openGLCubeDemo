#version 330 core
out vec4 FragColor;

in vec2 texCoord;

uniform sampler2D texture0;
uniform vec3 uColor;
uniform int uFaceConfig;

void main()
{
    FragColor = (uColor.x >= 0.0 ? vec4(uColor, 1.0) : texture(texture0, texCoord));
}