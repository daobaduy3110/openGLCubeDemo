#version 330 core
precision highp int;
out vec4 FragColor;

in vec2 texCoord;
flat in int isChangeColor;

uniform sampler2D texture0;
uniform vec3 uColor;
uniform vec3 cubeColor;

void main()
{
    FragColor = (isChangeColor >= 0 ? vec4(uColor, 1.0) : vec4(cubeColor, 1.0));
}