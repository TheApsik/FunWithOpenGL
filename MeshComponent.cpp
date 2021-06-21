#include "MeshComponent.h"
#include "Object.h"
#include "Drawer.h"
#include "RendererManager.h"

MeshComponent::MeshComponent():Component(), mesh(nullptr), observers()
{

}

void MeshComponent::Start(){
}

void MeshComponent::Update()
{
	RendererManager& mRenderer = RendererManager::getInstance();
	mRenderer.addToPipe(mesh, *this);
}


void MeshComponent::Render(ShaderProgram& program, DrawMethod method)
{
	Vector3 position = parent->getGlobalPosition();
	program.addUniformVector<>("objectPosition", FLOAT, 1, &position);
	for (auto it = observers.begin(); it != observers.end(); it++)
		(*it)->Adjust();
	//std::cout << "tu2";
}

void MeshComponent::attach(MeshObserver* observer)
{
	observers.push_back(observer);
}
