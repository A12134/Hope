#include "baseCam.h"



baseCam::baseCam(window* _w, float fov, float width, float height, float nearz, float farz)
{
	this->w = _w;
	this->projection = perspective(radians(fov), width / height, nearz, farz);
}


baseCam::baseCam(window* _w, float left, float right, float bot, float top, float nearz, float farz)
{
	this->w = _w;
	this->projection = ortho(left, right, bot, top, nearz, farz);
}

baseCam::~baseCam()
{
}
