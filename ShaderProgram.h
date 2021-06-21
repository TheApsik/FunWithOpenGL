#pragma once
#include <gl/glew.h>
#include <string>
#include <map>
#include "Shader.h"
#include "OpenGL.h"
#include "Attribute.h"

class ShaderProgram
{
private:
	struct idAttribute {
		GLint id;
		Attribute* attribute;
	};

	GLuint id;
	std::map<std::string, idAttribute> attributes;
public:
	ShaderProgram();

	void attachShader(Shader& shader);
	void link();
	void use();
	void bindFragmentOutput(std::string name, unsigned location);
	void addAttribute(std::string name, Attribute& attribute);
	template<typename T>
	void addUniformVector(std::string name, Primitive primitive, size_t count, T* value);
	template<typename T>
	void addUniformMatrix(std::string name, size_t count, bool transpose, T* value);
	void addUniformVariable(std::string name, GLint value);
	void addUniformVariable(std::string name, GLfloat value);
	void addUniformVariable(std::string name, GLuint value);
	void bindAttribute(std::string name);
	

	~ShaderProgram();
};

template<typename T>
inline void ShaderProgram::addUniformVector(std::string name, Primitive primitive, size_t count, T* value){
	GLint uID = glGetUniformLocation(this->id, name.c_str());
	if (uID == -1)
		throw std::invalid_argument("Uniform variable with name: " + name + " doesn't exist.");
	
	switch (primitive)
	{
	case INT:
		glUniform3iv(uID, count, (GLint*) value);
	case FLOAT:
		glUniform3fv(uID, count, (GLfloat*) value);
	default:
		break;
	}
}

template<typename T>
inline void ShaderProgram::addUniformMatrix(std::string name, size_t count, bool transpose, T* value)
{
	GLint uID = glGetUniformLocation(this->id, name.c_str());
	if (uID == -1)
		throw std::invalid_argument("Uniform matrix with name: " + name + " doesn't exist.");

	glUniformMatrix4fv(uID, count, transpose, value);
}
