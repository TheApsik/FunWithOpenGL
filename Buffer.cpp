#include "Buffer.h"

Buffer::Buffer(BufferType type): type(type)
{
	glCreateBuffers(1, &this->id);
    ErrorCheck();
	GLboolean isCreated = glIsBuffer(this->id);
	do {
		isCreated = glIsBuffer(this->id);
	} while (isCreated != GL_TRUE);
}

Buffer::Buffer(Buffer&& other):id(other.id), type(other.type)
{
	std::cout << "[MOVED] Buffer id: " << this->id << std::endl;
	other.id = 0;
}

void Buffer::bind()
{
	glBindBuffer(this->type, this->id);
	ErrorCheck();
}

BufferType Buffer::getType()
{
	return this->type;
}

Buffer::~Buffer()
{
	std::cout << "[DESTROY] Buffer id: " << this->id << std::endl;
	glDeleteBuffers(1, &this->id);
	ErrorCheck();
}
