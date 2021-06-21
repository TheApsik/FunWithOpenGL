#pragma once
#include <GL/glew.h>
#include <string>
#include "File.h"
#include "OpenGL.h"

enum ShaderType {
	VERTEX = GL_VERTEX_SHADER,
	FRAGMENT = GL_FRAGMENT_SHADER,
	GEOMETRY = GL_GEOMETRY_SHADER,
	COMPUTE = GL_COMPUTE_SHADER,
	TESSELLATION_CONTROL = GL_TESS_CONTROL_SHADER,
	TESSELLATION_EVALUATION = GL_TESS_EVALUATION_SHADER,
	UNKNOWN = -1
};

class Shader {
private:
	const GLuint id;
	const ShaderType type;
	std::string source;
public:
	Shader(ShaderType type, std::string path);
	~Shader();
	
	friend class ShaderCompiler;
	friend class ShaderProgram;
};