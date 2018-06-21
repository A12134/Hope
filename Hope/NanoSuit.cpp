#include "NanoSuit.h"




NanoSuit::NanoSuit(transformation transform, shaderProgram * sp, model * meshes, LogManager * engineLog):
	gameObject(transform, sp, meshes, engineLog)
{

}

NanoSuit::~NanoSuit()
{
}
