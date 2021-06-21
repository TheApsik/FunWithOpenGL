#pragma once
#include <GL/glew.h>
#include "Image.h"
class Texture
{
private:
	GLuint id;
	Image& image;

public:
	Texture(Image& image);

	void bind();

	~Texture();
};

