#pragma once
#include "Component.h"
#include "Vector3.h"
#include "Object.h"
class ObjectMovmentControler : public Component
{
private:
	Vector3 velocity;
public:
	void Start();
	void Update();
};

