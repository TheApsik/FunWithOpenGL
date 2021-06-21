#include "Renderer.h"
#include <glm/glm.hpp>
#include<glm/gtc/type_ptr.hpp>

void Renderer::placeCamera()
{
	glm::mat4 model = glm::mat4(1.0f);
	//model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	this->program.addUniformMatrix<>("model", 1, false, glm::value_ptr(model));

	glm::mat4 view = camera.getLookAt();
	this->program.addUniformMatrix<>("view", 1, false, glm::value_ptr(view));


	glm::mat4 projection = glm::perspective(glm::radians(45.0f), getProportion(), 0.006f, 1000.0f);
	this->program.addUniformMatrix<>("projection", 1, false, glm::value_ptr(projection));
}

Renderer::Renderer(ShaderProgram& program, Camera& camera, DrawMethod method)
	:program(program), camera(camera), method(method), posX(0), posY(0), width(1280), height(720){}


void Renderer::setCamera(Camera camera)
{
	this->camera = camera;
}

void Renderer::render(Drawable& model, std::vector<Renderable*>& renderSettings)
{
	model.BindDrawing(this->program);
	for (auto it = renderSettings.begin(); it != renderSettings.end(); it++)
	{
		(*it)->Render(program, method);
		model.Draw(method);
	}

}

void Renderer::clear()
{
	glClearColor(0.2f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::setViewport(int startX, int startY, int width, int height)
{
	this->posX = startX;
	this->posY = startY;
	this->width = width;
	this->height = height;
	glViewport(startX, startY, startX + width, startY + height);
}

float Renderer::getProportion() const
{
	return static_cast<float>(width) / static_cast<float>(height);
}

Renderer::~Renderer()
{
	std::cout << "[DESTROY]";
}
