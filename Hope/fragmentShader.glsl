#version 330 core

struct DirectionalLight
{
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct PointLight
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float constant;
	float linear;
	float quadratic;
};
struct SpotLight
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	vec3 direction;
	float cutoffAngle;
};

out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D Diffuse_0;
uniform sampler2D Diffuse_1;
uniform sampler2D Diffuse_2;
uniform sampler2D Diffuse_3;

uniform sampler2D Specular_0;
uniform sampler2D Specular_1;
uniform sampler2D Specular_2;
uniform sampler2D Specular_3;

uniform sampler2D Normal_0;
uniform sampler2D Normal_1;
uniform sampler2D Normal_2;
uniform sampler2D Normal_3;

void main()
{
	FragColor = texture(Diffuse_0, TexCoord);
}