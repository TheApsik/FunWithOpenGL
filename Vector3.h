#pragma once
#include <GL/glew.h>
#include <iostream>
#include <string>

using namespace std;
struct Vector3
{
	GLfloat x, y, z;

	string toString();
	Vector3();
	Vector3(GLfloat x, GLfloat y, GLfloat z);

	Vector3& operator+=(const Vector3& vector);

	static void random(Vector3& vector, float from = 0.0f, float to = 1.0f);
};
