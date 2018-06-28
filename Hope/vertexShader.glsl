#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 transform;
uniform mat4 model;

out vec3 FragPos;
out vec3 ourColor;
out vec2 TexCoord;
//out vec3 FragPos;

void main()
{
	gl_Position = transform*vec4(aPos, 1.0);
	ourColor = aPos;
	FragPos = vec3(model*vec4(aPos,1.0));
	TexCoord = aTexCoord;
}