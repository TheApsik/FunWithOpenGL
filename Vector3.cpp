#include "Vector3.h"

Vector3::Vector3() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3::Vector3(GLfloat x, GLfloat y, GLfloat z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3& Vector3::operator+=(const Vector3& vector)
{
	this->x += vector.x;
	this->y += vector.y;
	this->z += vector.z;
	return *this;
}

void Vector3::random(Vector3& vector, float from, float to)
{
	vector.x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / to) + from;
	vector.y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / to) + from;
	vector.z = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / to) + from;
}

string Vector3::toString() {
	string str = "Vec3["
		+ to_string(this->x) + ", "
		+ to_string(this->y) + ", "
		+ to_string(this->z) + "]";
	return str;
}