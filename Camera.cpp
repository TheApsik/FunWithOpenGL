#include "Camera.h"
#include <glm/gtx/rotate_vector.hpp>
glm::mat4 Camera::getLookAt()
{
	return glm::lookAt(position, position+direction, up);
}

void Camera::rotate(float angle, glm::vec3 axis)
{
	direction = glm::rotate(direction, angle, axis);
}

Camera::Camera(glm::vec3 position, glm::vec3 direction, glm::vec3 up) :
	position(position), direction(glm::normalize(direction)), up(up){}

Camera::Camera() : position( .0f, .0f, 3.0f), 
					 direction( .0f, .0f, -1.0f),
					     up( .0f, 1.0f, .0f) {}
