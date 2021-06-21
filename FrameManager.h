#pragma once
#include "Frame.h"
class FrameManager
{
private:
	static Frame* main;
public:
	static void setMainFrame(Frame& frame);
	static sf::Vector2f getMousePosition();
	static void setCoursorCenter();
	static bool isFucus;
};