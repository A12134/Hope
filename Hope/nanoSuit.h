#ifndef NANO_SUIT_H
#define NANO_SUIT_H
#include "gameObject.h"
class nanoSuit :
	public gameObject
{
public:
	nanoSuit(transformation transform, shaderProgram* sp, model* meshes, LogManager* engineLog);
	~nanoSuit();
	
	void update(float deltaSec);
};
#endif
