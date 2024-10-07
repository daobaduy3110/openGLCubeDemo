#version 330 core
precision highp int;
out vec4 FragColor;

in vec2 texCoord;
flat in int isChangeColor;

uniform sampler2D texture0;
uniform vec3 uColor;
uniform vec3 cubeColor;
uniform bool useTexture;

void main()
{
    FragColor = useTexture ? texture(texture0, texCoord) : vec4(isChangeColor >= 0 ? uColor : cubeColor, 1.0);
}