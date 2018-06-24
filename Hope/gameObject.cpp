#include "gameObject.h"




gameObject::gameObject(transformation transform, shaderProgram* sp, model* meshes, LogManager* engineLog)
{
	this->transform = transform;
	this->sp = sp;
	this->mesh = meshes;
	this->engineLog = engineLog;
}

gameObject::~gameObject()
{
}

void gameObject::render(camera* cam)
{
	glm::mat4 model = glm::mat4(1.0f);
	model = translate(model, transform.position);
	model = scale(model, transform.scale);
	model = rotate(model, glm::radians(transform.rotation), transform.rotationAxis);
	//mat4 view = cam->getViewMatrix();
	mat4 projection = cam->getProjectionMatrix();

	if(mesh != nullptr)
	{
		mesh->render(this->transform.position, cam, sp, model);
	}
}
