#pragma once
#include "Component.h"
#include "Renderer.h"
#include "AnaglyphStereoscopeRenderer.h"
#include "SbSStereoscopeRenderer.h"
#include "RendererManager.h"
class RendererSwaper: public Component
{
private:
	Renderer renderer;
	AnaglyphStereoscopeRenderer anaglyphRenderer;
	SbSStereoscopeRenderer sbsRenderer;
	RendererManager& manager;

	Renderer* selected;
	void setRenderer(Renderer& rend);
	void setEyesDistance();
public:
	float eyesDistance;
	RendererSwaper(ShaderProgram& program, Camera& camera, int width, int height);
	void Update();
};

