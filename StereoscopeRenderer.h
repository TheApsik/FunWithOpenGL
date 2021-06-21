#pragma once
#include "Renderer.h"
#include <glm/glm.hpp>
class StereoscopeRenderer : public Renderer
{
protected:
	void placeCamera();
private:
	glm::mat4 StereoProjection(float horizon, float _near, float _far, float _zero_plane, float _dist);

public:
	float eyesDistance;
	StereoscopeRenderer(ShaderProgram& program, Camera& camera, DrawMethod method);
};

