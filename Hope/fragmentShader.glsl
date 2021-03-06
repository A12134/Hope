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
in vec3 n;
in vec3 T;
in vec3 B;
in mat3 TBN;
//in vec3 normal;
//in vec3 FragPos;
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

vec4 CalcDirLight(DirectionalLight light, vec3 normal, vec3 viewDir)
{
	vec3 lightDir = normalize(-light.direction);

	float diff = max(dot(normal, lightDir), 0.0f);

	vec3 h = normalize(lightDir + viewDir);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(normal, h), 0.0f), 64.0f);
	vec4 diffuseMap =  texture(Diffuse_0, TexCoord) + texture(Diffuse_1, TexCoord) + texture(Diffuse_2, TexCoord) + texture(Diffuse_3, TexCoord);
	vec4 ambient = vec4(light.ambient,1.0) * diffuseMap;
	vec4 diffuse = vec4(light.diffuse,1.0) * diff * diffuseMap;
	vec4 specularMap = texture(Specular_0, TexCoord)+texture(Specular_1, TexCoord)+texture(Specular_2, TexCoord)+texture(Specular_3, TexCoord);
	vec4 specular = vec4(light.specular,1.0) * spec * specularMap;

	//return (max(dot(normal, lightDir), 0.0f));
	return(ambient + diffuse + specular);
	//return(lightDir);
}

void main()
{
	vec3 normal = vec3(texture(Normal_0, TexCoord));
	normal = normalize(normal*2.0 - 1.0);
	normal = normalize(TBN * normal);
	//normal = mat3(transpose(inverse(models)))*normal;
	//norm.y = -norm.y;
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 norm = n;
	//if (dot(vec3(0,0,norm.z), -viewDir) < 0.0)
	//{
	//	norm.z = norm.z*-1.0;
		//norm.x = norm.x*-1.0;
	//}
	//float x = CalcDirLight(light, normal, viewDir);
	FragColor = CalcDirLight(light, normal, viewDir);
	//FragColor = vec4(x,x,x,1.0f);
	//FragColor = vec4(n*0.5+0.5, 1.0);
}