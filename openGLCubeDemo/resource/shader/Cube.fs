#version 330 core
out vec4 FragColor;

//in vec3 color;
in vec2 texCoord;

uniform sampler2D texture0;
uniform vec3 uColor;

void main()
{
    FragColor = (uColor.x >= 0.0 ? vec4(uColor, 1.0) : texture(texture0, texCoord));
}