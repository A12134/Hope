#version 330 core

in vec3 ourColor;
in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D Diffuse_0;
uniform sampler2D Diffuse_1;

uniform sampler2D Specular_0;
uniform sampler2D Specular_1;

uniform sampler2D Normal_0;
uniform sampler2D Normal_1;

uniform vec3 color;

void main()
{
	FragColor = texture(Diffuse_0, TexCoord);
}