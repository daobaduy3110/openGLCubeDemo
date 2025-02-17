#version 330 core
precision highp int;
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in float aFaceID;

out vec2 texCoord;
flat out int isChangeColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform int uFaceConfig;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    texCoord = vec2(aTexCoord.x, aTexCoord.y);
    // get the flag for this face
    int faceConfig = (uFaceConfig >> int(aFaceID)) & 1;
    isChangeColor = (faceConfig == 1 ? 100 : -100);
}