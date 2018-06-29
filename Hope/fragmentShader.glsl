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

in vec3 FragPos;
in vec3 ourColor;
in vec2 TexCoord;
in mat3 TBN;
in mat4 models;

uniform vec3 viewPos;

uniform sampler2D Normal_0;
uniform sampler2D Normal_1;
uniform sampler2D Normal_2;
uniform sampler2D Normal_3;

uniform sampler2D Diffuse_0;
uniform sampler2D Diffuse_1;
uniform sampler2D Diffuse_2;
uniform sampler2D Diffuse_3;

uniform sampler2D Specular_0;
uniform sampler2D Specular_1;
uniform sampler2D Specular_2;
uniform sampler2D Specular_3;

uniform DirectionalLight light;

vec3 CalcDirLight(DirectionalLight light, vec3 normal, vec3 viewDir)
{
	vec3 lightDir = normalize(-light.direction);

	float diff = max(dot(normal, lightDir), 0.0f);

	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), 0.8f);
	vec3 diffuseMap =  (vec3(texture(Diffuse_0, TexCoord)) + vec3(texture(Diffuse_1, TexCoord)) + vec3(texture(Diffuse_2, TexCoord)) + vec3(texture(Diffuse_3, TexCoord)));
	vec3 ambient = light.ambient * diffuseMap;
	vec3 diffuse = light.diffuse * diff * diffuseMap;
	vec3 specularMap = (vec3(texture(Specular_0, TexCoord))+vec3(texture(Specular_1, TexCoord))+vec3(texture(Specular_2, TexCoord))+vec3(texture(Specular_3, TexCoord)));
	vec3 specular = light.specular * spec * specularMap;

	//return (max(dot(normal, lightDir), 0.0f));
	return(ambient + diffuse + specular);
}

void main()
{
	vec3 normal = texture(Normal_0, TexCoord).rgb;
	normal = normalize(normal*2.0 - 1.0);
	normal = normalize(TBN * normal);
	//normal = mat3(transpose(inverse(models)))*normal;
	//norm.y = -norm.y;
	vec3 viewDir = normalize(viewPos - FragPos);
	//float x = CalcDirLight(light, normal, viewDir);
	//FragColor = vec4(CalcDirLight(light, normal, viewDir), 1.0f );
	//FragColor = vec4(x,x,x,1.0f);
	FragColor = vec4(normal, 1.0);
}