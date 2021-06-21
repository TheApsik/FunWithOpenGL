#include "FrameManager.h"

void FrameManager::setMainFrame(Frame& frame)
{
	FrameManager::main = &frame;
}

sf::Vector2f FrameManager::getMousePosition()
{
	sf::Vector2f windowSize = sf::Vector2f(main->window.getSize());
	sf::Vector2f mousePosition = (sf::Vector2f(sf::Mouse::getPosition(main->window)) - (windowSize / 2.0f))/windowSize.x;
	//std::cout << mousePosition.x << ", " << mousePosition.y;
	return mousePosition;
}

void FrameManager::setCoursorCenter()
{
	sf::Mouse::setPosition(sf::Vector2i(main->window.getSize()) / 2, main->window);
}

bool FrameManager::isFucus = true;
Frame* FrameManager::main = nullptr;