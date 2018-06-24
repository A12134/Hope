#ifndef NANO_SUIT_H
#define NANO_SUIT_H
#include "gameObject.h"
class NanoSuit :
	public gameObject
{
public:
	NanoSuit(transformation transform, shaderProgram* sp, model* meshes, LogManager* engineLog);
	~NanoSuit();

	void update(float deltaSec);
};
#endif

