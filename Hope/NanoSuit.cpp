#include "NanoSuit.h"




NanoSuit::NanoSuit(transformation transform, shaderProgram * sp, model * meshes, LogManager * engineLog):
	gameObject(transform, sp, meshes, engineLog)
{

}

NanoSuit::~NanoSuit()
{
}

void NanoSuit::update(float deltaSec)
{
	this->transform.rotation += 45.0f * deltaSec;
}
