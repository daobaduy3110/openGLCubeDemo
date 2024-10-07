#version 330 core
precision highp int;
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in int  aFaceID;

out vec2 texCoord;
out vec3 applyColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform int uFaceConfig;
uniform vec3 uColor;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    texCoord = vec2(aTexCoord.x, aTexCoord.y);
    // get the flag for this face
    int faceConfigID = (uFaceConfig >> aFaceID) & 1;
    applyColor = (faceConfigID == aFaceID ? uColor : vec3(-1.0, 0.0, 0.0));
}