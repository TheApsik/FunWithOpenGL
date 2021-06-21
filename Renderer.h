#pragma once
#include <vector>
#include <GL/glew.h>
#include "Camera.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Drawable.h"
#include "Renderable.h"

class Renderer
{
protected:
	ShaderProgram& program;
	Camera& camera;
	virtual void placeCamera();
	int posX, posY, width, height;

private:
	DrawMethod method;


public:
	Renderer(ShaderProgram& program, Camera& camera, DrawMethod method);
	void setCamera(Camera camera);
	virtual void render(Drawable& model, std::vector<Renderable*>& renderSettings);
	void clear();
	void setViewport(int startX, int startY, int width, int height);
	float getProportion() const;
	~Renderer();

	friend class RendererManager;
};

