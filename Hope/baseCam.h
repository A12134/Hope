#ifndef BASE_CAM_H
#define BASE_CAM_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

class baseCam
{
private:
	mat4 projection;
public:
	// perspective projection
	// fov: degrees
	baseCam(float fov, float width, float height, float nearz, float farz);
	// orthographic projection
	baseCam(float left, float right, float bot, float top, float near, float far);
	~baseCam();

	mat4 getProjectionMatrix() { return projection; }
};
#endif

