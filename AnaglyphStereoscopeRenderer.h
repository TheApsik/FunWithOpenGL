#pragma once
#include "StereoscopeRenderer.h"
#include <glm/glm.hpp>
class AnaglyphStereoscopeRenderer : public StereoscopeRenderer
{
public:
	void render(Drawable& model, std::vector<Renderable*>& renderSettings);
	AnaglyphStereoscopeRenderer(ShaderProgram& program, Camera& camera, DrawMethod method);
};

