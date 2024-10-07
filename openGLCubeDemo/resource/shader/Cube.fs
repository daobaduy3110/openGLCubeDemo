#version 330 core
out vec4 FragColor;

in vec3 color;
in vec2 uv;

uniform sampler2D texture0;

void main()
{
    FragColor = color.x >= 0 ? vec4(color, 1.0f) : texture(texture0, uv);
}