#pragma once
#include <GL/glew.h>
#include <vector>
#include <iostream>
#include "OpenGL.h"

enum BufferType {
	ARRAY = GL_ARRAY_BUFFER,
	ELEMENT_ARRAY =  GL_ELEMENT_ARRAY_BUFFER
	//TODO:
};

enum BufferUsage {
	STREAM_DRAW = GL_STREAM_DRAW,
	STATIC_DRAW = GL_STATIC_DRAW
	//TODO:
};

class Buffer
{
private:
	GLuint id;
	BufferType type;

public:
	Buffer(BufferType type);
	Buffer(Buffer&& other);

	void bind();

	BufferType getType();

	template<typename T>
	void setData(std::vector<T> data, BufferUsage usage);

	~Buffer();
};

template<typename T>
inline void Buffer::setData(std::vector<T> data, BufferUsage usage)
{
	glNamedBufferData(this->id, data.size() * sizeof(T), &data[0], usage);
}
