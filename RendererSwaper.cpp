#include "RendererSwaper.h"
#include <SFML/Window.hpp>

void RendererSwaper::setRenderer(Renderer& rend)
{
	manager.setRenderer(rend);
	selected = &rend;
	setEyesDistance();
}

void RendererSwaper::setEyesDistance()
{
	if (selected != &renderer) {
		((StereoscopeRenderer*)selected)->eyesDistance = eyesDistance;
	}
}

RendererSwaper::RendererSwaper(ShaderProgram& program, Camera& camera, int width, int height)
	:renderer(program, camera, TRIANGLES), anaglyphRenderer(program, camera, TRIANGLES), sbsRenderer(program, camera, TRIANGLES), manager(RendererManager::getInstance()), eyesDistance(0.05), selected(&renderer)
{
	renderer.setViewport(0, 0, width, height);
	anaglyphRenderer.setViewport(0, 0, width, height);
	sbsRenderer.setViewport(0, 0, width, height);

	manager.setRenderer(renderer);
}

void RendererSwaper::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F9)) {
		setRenderer(renderer);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F10)) {
		setRenderer(anaglyphRenderer);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) {
		setRenderer(sbsRenderer);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add)) {
		eyesDistance += 0.001f;
		setEyesDistance();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract)){
		eyesDistance -= 0.001f;
		setEyesDistance();
	}

}
