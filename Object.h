#pragma once
#include "Mesh.h"
#include "Buffer.h"
#include "Vector3.h"
#include "Component.h"
class Object
{
private:
	void bindPosition();
	void bindMesh();

	void updateComponents();

	std::map<std::string, std::vector<std::unique_ptr<Component>>> components;

public:
	Mesh* mesh;
	Vector3 position;
	Object(Mesh& mesh);
	Object();
	~Object();

	Vector3 getGlobalPosition();

	template<typename T, typename std::enable_if<std::is_base_of<Component, T>::value>::type* = nullptr>
	T* getComponent() {
		std::string name(typeid(T).name());
		if (components.find(typeid(T).name()) == components.end())
			return nullptr;
		else
			return (T*)components[name].front().get();
	}

	template<typename T, typename std::enable_if<std::is_base_of<Component, T>::value>::type* = nullptr>
	void addComponent(T& component) {
		T* newComponent = new T(component);
		std::string name(typeid(T).name());
		std::vector<std::unique_ptr<Component>>& arr = components[name];
		arr.push_back(std::unique_ptr<Component>((Component*)(newComponent)));
		T& c = (T&)*arr.back();
		c.parent = this;
		c.Start();
	}

	friend class Scene;
};