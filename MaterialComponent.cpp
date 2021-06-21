#include "MaterialComponent.h"
#include "Object.h"
#include "MeshComponent.h"

void MaterialComponent::Start()
{
	MeshComponent* mesh = parent->getComponent<MeshComponent>();
	mesh->attach(this);
}

void MaterialComponent::Adjust()
{
	texture->bind();
}
