#pragma once
#include<string>
#include<SFML/Window.hpp>
#include<iostream>
#include "RendererManager.h"
#include "Scene.h"

class Frame
{
private:
	sf::ContextSettings settings;
	sf::Window window;

public:
	Frame(int width, int height, std::string title);
	void start(Scene& scena);

	friend class FrameManager;
};

