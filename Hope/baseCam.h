#ifndef BASE_CAM_H
#define BASE_CAM_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "window.h"

using namespace glm;

class baseCam
{
private:
	mat4 projection;

protected:
	window * w;

public:
	// perspective projection
	// fov: degrees
	baseCam(window* _w, float fov, float width, float height, float nearz, float farz);
	// orthographic projection
	baseCam(window* _w, float left, float right, float bot, float top, float near, float far);
	~baseCam();

	mat4 getProjectionMatrix() { return projection; }
};
#endif

