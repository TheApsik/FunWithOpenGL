#pragma once
#include "ShaderProgram.h"

enum DrawMethod {
	TRIANGLES = GL_TRIANGLES
};

enum DrawMethod;
class Drawable
{
public:
	virtual void BindDrawing(ShaderProgram& sProgram) = 0;
	virtual void Draw(DrawMethod method) = 0;
};

