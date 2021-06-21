#include "Drawer.h"

void Drawer::Draw(Drawable& element, ShaderProgram& program, DrawMethod method)
{
	element.Draw(method);
}
