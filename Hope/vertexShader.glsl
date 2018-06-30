#version 330 core
layout (location = 0) in vec3 aBitangent;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in vec3 aTangent;
layout (location = 4) in vec3 aPos;

uniform mat4 transform;
uniform mat4 model;

out vec3 FragPos;
out vec3 ourColor;
out vec2 TexCoord;
out vec3 n;
out vec3 T;
out vec3 B;
out mat3 TBN;
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
	n = normalize(aNormal);
	T = normalize(vec3(model * vec4(aTangent, 0.0f)));
	B = normalize(vec3(model * vec4(aBitangent, 0.0f)));
	//n.y = -n.y;
	//B = aBitangent;
	vec3 N = normalize(vec3(transpose(inverse(model)) * vec4(aNormal, 0.0f)));
	//T = normalize(T - dot(T,N)*N);
	//vec3 B = cross(N, T);
	if (dot(cross(N,T),B) < 0.0)
		T = T * -1.0;

	TBN = mat3(T,B,N);
	//normal = normalize(vec3(texture(Normal_0, TexCoord)));
	//normal = mat3(transpose(inverse(model)))*normal;
}