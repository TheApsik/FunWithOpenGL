#include "AnaglyphStereoscopeRenderer.h"
#include<glm/gtc/type_ptr.hpp>


void AnaglyphStereoscopeRenderer::render(Drawable& model, std::vector<Renderable*>& renderSettings)
{
	//glDrawBuffer(GL_BACK_LEFT);
	glColorMask(true, false, false, false);
	ErrorCheck();
	Renderer::render(model, renderSettings);

	eyesDistance = -eyesDistance;
	placeCamera();
	glClear(GL_DEPTH_BUFFER_BIT);
	ErrorCheck();
	//glDrawBuffer(GL_BACK_RIGHT); // GPU dosen't suport
	glColorMask(false, false, true, false);
	ErrorCheck();
	Renderer::render(model, renderSettings);

	eyesDistance = -eyesDistance;
	placeCamera();
	glColorMask(true, true, true, true);
	ErrorCheck();
}

AnaglyphStereoscopeRenderer::AnaglyphStereoscopeRenderer(ShaderProgram& program, Camera& camera, DrawMethod method)
	:StereoscopeRenderer(program, camera, method)
{}
