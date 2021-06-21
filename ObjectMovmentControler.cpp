#include "ObjectMovmentControler.h"
//#include "Object.h"

void ObjectMovmentControler::Start()
{
	Vector3::random(velocity, 0, 0.02f);
}

void ObjectMovmentControler::Update()
{
	parent->position += velocity;
}
