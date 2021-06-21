#pragma once
#include "Object.h"
class Scene
{
private:
	std::vector<Object*> objects;
public:
	Scene();
	void add(Object& object);
	void update();
};

