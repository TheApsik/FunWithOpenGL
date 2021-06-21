#include "SbSStereoscopeRenderer.h"
#include<glm/gtc/type_ptr.hpp>


SbSStereoscopeRenderer::SbSStereoscopeRenderer(ShaderProgram& program, Camera& camera, DrawMethod method)
	:StereoscopeRenderer(program, camera, method)
{}

void SbSStereoscopeRenderer::render(Drawable& model, std::vector<Renderable*>& renderSettings)
{
	int halfWidth = width / 2;
	glViewport(posX, posY, halfWidth, height);
	Renderer::render(model, renderSettings);
	eyesDistance = -eyesDistance;
	placeCamera();
	glViewport(width-halfWidth+posX, 0, halfWidth, height);
	Renderer::render(model, renderSettings);
	eyesDistance = -eyesDistance;
	placeCamera();
}
