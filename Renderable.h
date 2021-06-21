#pragma once
#include "ShaderProgram.h"
#include "Drawable.h"
class Renderable
{
public:
	virtual void Render(ShaderProgram& program, DrawMethod method) = 0;
};

