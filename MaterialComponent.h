#pragma once
#include "Component.h"
#include "MeshObserver.h"
#include "Texture.h"
class MaterialComponent: public Component, public MeshObserver
{
public:
	Texture* texture;
	void Start();
	void Adjust();
};

