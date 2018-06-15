#include "baseCam.h"



baseCam::baseCam(float fov, float width, float height, float nearz, float farz)
{
	this->projection = perspective(radians(fov), width / height, nearz, farz);
}


baseCam::baseCam(float left, float right, float bot, float top, float near, float far)
{
	this->projection = ortho(left, right, bot, top, near, far);
}

baseCam::~baseCam()
{
}
