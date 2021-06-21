#include "Scene.h"

Scene::Scene():objects()
{
}

void Scene::add(Object& object)
{
	objects.push_back(&object);
}

void Scene::update()
{
	for (Object* object : objects) {
		object->updateComponents();
	}
}
