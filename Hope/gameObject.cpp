#include "gameObject.h"




gameObject::gameObject(transformation transform, shaderProgram* sp, LODmesh* meshes, LogManager* engineLog)
{
	this->transform = transform;
	this->sp = sp;
	this->meshes = meshes;
	this->engineLog = engineLog;
}

gameObject::~gameObject()
{
}

void gameObject::render(camera* cam)
{
	mat4 model;
	model = translate(model, transform.position);
	model = scale(model, transform.scale);
	model = rotate(model, transform.rotation, transform.rotationAxis);
	mat4 view = cam->getViewMatrix();
	mat4 projection = cam->getProjectionMatrix();

	if(meshes != nullptr)
	{
		meshes->render(sp, projection, view, model);
	}
}
