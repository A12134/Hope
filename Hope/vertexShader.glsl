#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 transform;
uniform mat4 model;



out vec3 FragPos;
out vec3 ourColor;
out vec2 TexCoord;
//out vec3 normal;
//out vec3 FragPos;
out mat4 models;

void main()
{
	gl_Position = transform*vec4(aPos, 1.0);
	ourColor = aPos;
	FragPos = vec3(model*vec4(aPos,1.0));
	TexCoord = aTexCoord;
	models = model;
	//normal = normalize(vec3(texture(Normal_0, TexCoord)));
	//normal = mat3(transpose(inverse(model)))*normal;
}