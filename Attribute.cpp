#include "Attribute.h"

unsigned Attribute::primitiveSize(Primitive primitive)
{
	switch (primitive) {
		case FLOAT:
			return sizeof(GLfloat);
		case UNSIGNED_INT:
			return sizeof(GLuint);
		default:
			return 0;
	}
}

Attribute::Attribute(size_t size, Primitive primitive, bool normalize, size_t offset)
	:size(size), primitive(primitive), normalize(normalize), offset(offset), amount(size/Attribute::primitiveSize(primitive))
{
}

