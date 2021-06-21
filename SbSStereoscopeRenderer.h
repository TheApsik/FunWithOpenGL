#pragma once
#include "StereoscopeRenderer.h"
#include <glm/glm.hpp>
class SbSStereoscopeRenderer: public StereoscopeRenderer
{
public:
	SbSStereoscopeRenderer(ShaderProgram& program, Camera& camera, DrawMethod method);
	void render(Drawable& model, std::vector<Renderable*>& renderSettings);
};

