#pragma once

class Object;
class Component
{
protected:
	Object* parent;
public:
	Component();
	virtual void Start(){};
	virtual void Update(){};

	friend class Object;
};

