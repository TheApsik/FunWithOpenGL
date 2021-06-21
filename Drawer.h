#pragma once
#include "Drawable.h"
class Drawer
{
public:
	static void Draw(Drawable& element, ShaderProgram& program, DrawMethod method);
};

