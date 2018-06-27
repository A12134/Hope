#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "model.h"
#include "LogManager.h"
#include "shaderProgram.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "camera.h"

using namespace glm;
using namespace std;

struct transformation
{
	transformation() {};
	transformation(vec3 _position, float _rotation, vec3 _scale) :
		position(_position),
		rotation(_rotation),
		scale(_scale),
		rotationAxis(vec3(0.0f, 1.0f, 0.0f))
	{};
	vec3 position;
	float rotation;
	vec3 scale;
	vec3 rotationAxis;
};

class gameObject
{
private:
	LogManager * engineLog;

protected:
	transformation transform;
	shaderProgram* sp;
	model* mesh;

public:
	gameObject();
	gameObject(transformation transform, shaderProgram* sp, model* meshes, LogManager* engineLog);
	~gameObject();

public:
	virtual void update(float deltaSec) = 0;
	virtual void render(camera* cam);
};
#endif

