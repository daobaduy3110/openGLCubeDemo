#version 330 core
out vec4 FragColor;

in vec2 uv;

uniform vec3 uColor;
uniform sampler2D texture0;

void main()
{
    FragColor = uColor.x >= 0 ? vec4(uColor, 1.0f) : texture(texture0, uv);
}