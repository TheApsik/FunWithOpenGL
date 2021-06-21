#include "Object.h"

void Object::bindPosition()
{
}

void Object::bindMesh()
{
}

void Object::updateComponents()
{
	for (auto& const pair : components) {
		std::vector<std::unique_ptr<Component>>& arr = pair.second;
		for (auto& component : arr){
			component->Update();
		}
	}
}

Object::Object(Mesh& mesh):position(.0f, .0f, .0f), mesh(&mesh){}

Object::Object() : position(.0f, .0f, .0f), mesh() {}

Object::~Object()
{
	std::cout << "[DESTROY] Object\n";
}

Vector3 Object::getGlobalPosition()
{
	return position;
}
