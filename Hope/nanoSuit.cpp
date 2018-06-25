#include "nanoSuit.h"




nanoSuit::nanoSuit(transformation transform, shaderProgram * sp, model * meshes, LogManager * engineLog) :
	gameObject(transform, sp, meshes, engineLog)
{
	
}

nanoSuit::~nanoSuit()
{
}

void nanoSuit::update(float deltaSec)
{
	this->transform.rotation += 45.0f * deltaSec;
}