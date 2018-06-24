#ifndef TEXTURE_H
#define TEXTURE_H
#include "LogManager.h"


enum class TEX_PARA {
	E_WRAP_REPEAT,
	E_WRAP_MIRRORED_REPEAT,
	E_WRAP_CLAMP_TO_EDGE,
	E_WRAP_CLAMP_TO_BORDER,
	E_FILTER_LINEAR,
	E_FILTER_NEAREST,
	E_FILTER_NEAREST_MIPMAP_NEAREST,
	E_FILTER_LINEAR_MIPMAP_NEAREST,
	E_FILTER_NEAREST_MIPMAP_LINEAR,
	E_FILTER_LINEAR_MIPMAP_LINEAR
};
class texture
{
private:
	unsigned int textureID;
	LogManager* engineLog;
public:
	texture(const char* filename, TEX_PARA warpMethod, TEX_PARA filterMethod, LogManager* engineLog);
	texture(const char* filename, TEX_PARA warpMethod_s, TEX_PARA warpMethod_t, TEX_PARA filterMethod_min, TEX_PARA filterMethod_mag, LogManager* engineLog);
	~texture();

	unsigned int getTexture() { return textureID; };

private:
	void loadImage(const char* filename);
};
#endif

