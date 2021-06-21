#pragma once
#include <string>
#include <gl/glew.h>
#include <stdexcept>

enum Primitive {
	FLOAT = GL_FLOAT,
	INT = GL_INT,
	UNSIGNED_INT = GL_UNSIGNED_INT,
	BYTE = GL_BYTE,
	UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
	SHORT = GL_SHORT,
	UNSIGNED_SHORT = GL_UNSIGNED_SHORT
};

class Attribute
{
private:
	size_t size;
	Primitive primitive;
	bool normalize;
	size_t offset;
	unsigned amount;

	static unsigned primitiveSize(Primitive primitive);

public:
	Attribute(size_t size, Primitive primitive, bool normalize, size_t offset = 0);
	friend class ShaderProgram;

	/*template<typename T>
	Attribute(std::string name, Primitive primitive, bool normalize, size_t offset) {
		unsigned amount = sizeof(T) / Attribute::primitiveSize(primitive);
		if (amount < 4)
			throw std::invalid_argument("Size of '" + typeid(T).name() + "' is larger than 3 bytes!");

		this->amount = amount;
	}*/
};

