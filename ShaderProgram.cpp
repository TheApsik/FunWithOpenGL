#include "ShaderProgram.h"

ShaderProgram::ShaderProgram():id(glCreateProgram()){
	ErrorCheck();
}

void ShaderProgram::attachShader(Shader& shader)
{
	glAttachShader(this->id, shader.id);
	ErrorCheck();
}

void ShaderProgram::link()
{
	glLinkProgram(this->id);
	ErrorCheck();
}

void ShaderProgram::use()
{
	glUseProgram(this->id);
	ErrorCheck();
}


void ShaderProgram::bindFragmentOutput(std::string name, unsigned location)
{
	glBindFragDataLocation(this->id, location, name.c_str());
	ErrorCheck();
}

void ShaderProgram::addAttribute(std::string name, Attribute& attribute)
{
	GLint idAtt = glGetAttribLocation(this->id, name.c_str());
	if (idAtt < 0)
		return;
		//throw std::invalid_argument("Attribute '" + name + "' doesn't exist in VERTEX SHADER.");

	attributes[name].id = idAtt;
	attributes[name].attribute = &attribute;
}

void ShaderProgram::addUniformVariable(std::string name, GLint value)
{
	GLint uID = glGetUniformLocation(this->id, name.c_str());
	if (uID == -1)
		throw std::invalid_argument("Uniform variable with name: " + name + " doesn't exist.");
	glUniform1i(uID, value);
}

void ShaderProgram::addUniformVariable(std::string name, GLfloat value)
{
	GLint uID = glGetUniformLocation(this->id, name.c_str());
	if (uID == -1)
		throw std::invalid_argument("Uniform variable with name: " + name + " doesn't exist.");
	glUniform1f(uID, value);
}

void ShaderProgram::addUniformVariable(std::string name, GLuint value)
{
	GLint uID = glGetUniformLocation(this->id, name.c_str());
	if (uID == -1)
		throw std::invalid_argument("Uniform variable with name: " + name + " doesn't exist.");
	glUniform1ui(uID, value);
}

void ShaderProgram::bindAttribute(std::string name)
{
	//TODO: move to Attribute
	Attribute* attribute = this->attributes[name].attribute;
	if (attribute != nullptr) {
		glEnableVertexAttribArray(this->attributes[name].id);
		ErrorCheck();
		glVertexAttribPointer(this->attributes[name].id, attribute->amount, attribute->primitive, attribute->normalize, attribute->size, (void*)attribute->offset);
		ErrorCheck();
	}
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(this->id);
	ErrorCheck();
}
