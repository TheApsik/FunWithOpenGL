#include "RendererManager.h"


RendererManager::RendererManager():pipeline()
{}

RendererManager& RendererManager::getInstance()
{
	static RendererManager instance;
	return instance;
}

void RendererManager::setRenderer(Renderer& renderer)
{
	this->renderer = &renderer;
	renderer.setViewport(renderer.posX, renderer.posY, renderer.width, renderer.height);
}

void RendererManager::addToPipe(Drawable* drawID, Renderable& element)
{
	pipeline[drawID].push_back(&element);
}

void RendererManager::renderAll()
{
	renderer->clear();
	renderer->placeCamera();
	
	auto it = pipeline.begin();
	while (it != pipeline.end()) {
		auto pair = &*it;
		if (pair->second.size() > 0) {
			renderer->render(*pair->first, pair->second);
			pair->second.clear();
			it++;
		}
		else
			it = pipeline.erase(it); // When in frame cicle there weren't call for Drawable model it gone erase.
	}
	//pipeline.clear();
}
