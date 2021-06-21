#include "Shader.h"
#include "ShaderCompiler.h"

Shader::Shader(ShaderType type, std::string path): type(type), id(glCreateShader(type))
{
	File shaderSource(path);
	source = shaderSource.getData();
	ShaderCompiler::compile(this);
}

Shader::~Shader()
{
	glDeleteShader(this->id);
	ErrorCheck();
}
