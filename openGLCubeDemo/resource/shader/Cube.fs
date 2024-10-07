#version 330 core
precision highp int;
out vec4 FragColor;

in vec2 texCoord;
in vec3 applyColor;

uniform sampler2D texture0;

void main()
{
    FragColor = (applyColor.x >= 0.0 ? vec4(applyColor, 1.0) : FragColor);
}