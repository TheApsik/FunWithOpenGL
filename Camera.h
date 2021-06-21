#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
class Camera
{
public:
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 up;

	glm::mat4 getLookAt();
	
	void rotate(float angle, glm::vec3 axis);

	Camera(glm::vec3 position, glm::vec3 direction, glm::vec3 up);
	Camera();
};

