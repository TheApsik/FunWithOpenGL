#pragma once
#include <vector>
#include "Renderer.h"
#include "Renderable.h"
class RendererManager
{
private:
	std::map<Drawable*, std::vector<Renderable*>> pipeline;
	//std::map<Drawable*, std::shared_ptr<std::vector<Renderable*>>> pipeline;
	Renderer* renderer;

	RendererManager();

public:
	static RendererManager& getInstance();
	void setRenderer(Renderer& renderer);
	void addToPipe(Drawable* drawID, Renderable& element);
	void renderAll();

	RendererManager(RendererManager const&) = delete;
	void operator=(RendererManager const&) = delete;
};

