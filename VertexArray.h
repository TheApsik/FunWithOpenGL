#pragma once
#include <GL/glew.h>
#include "OpenGL.h"
class VertexArray
{
private:
	GLuint id;
public:
	VertexArray();

	void bind();
	void unbind();

	~VertexArray();
};

