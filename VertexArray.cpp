#include "VertexArray.h"

VertexArray::VertexArray(){
	glGenVertexArrays(1, &this->id);
	ErrorCheck();
}

void VertexArray::bind()
{
	glBindVertexArray(this->id);
	ErrorCheck();
}

void VertexArray::unbind()
{
	glBindVertexArray(0);
	ErrorCheck();
}

VertexArray::~VertexArray()
{
	std::cout << "[DESTROY VertexArray] \n";
	glDeleteVertexArrays(1, &this->id);
	ErrorCheck();
}
