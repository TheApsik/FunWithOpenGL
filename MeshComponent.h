#pragma once
#include "Component.h"
#include "Mesh.h"
#include "Renderable.h"
#include "MeshObserver.h"

class MeshComponent: public Component, public Renderable
{
private:
	std::vector<MeshObserver*> observers;
public:
	Mesh* mesh;
	MeshComponent();
	
	void Render(ShaderProgram& program, DrawMethod method);
	void attach(MeshObserver* observer);
	
	void Start();
	void Update();
};

