#include "ShaderCompiler.h"
bool ShaderCompiler::debugMode = true;

std::string ShaderCompiler::shaderType(ShaderType type)
{
	switch (type) {
		case VERTEX:
			return "VERTEX";
		case FRAGMENT:
			return "FRAGMENT";
		case GEOMETRY:
			return "GEOMETRY";
		case COMPUTE:
			return "COMPUTE";
		case TESSELLATION_CONTROL:
			return "TESELATION_CONTROL";
		case TESSELLATION_EVALUATION:
			return "TESSELATION_EVALUATION";
		case UNKNOWN:
			return "UNKNOWN";
	}
}

void ShaderCompiler::compile(Shader* shader)
{
	const char* src = shader->source.c_str();
	glShaderSource(shader->id, 1, &src, NULL);
	ErrorCheck();
	glCompileShader(shader->id);
	ErrorCheck();

	if (ShaderCompiler::debugMode) {
		GLint isComplite = GL_FALSE;
		glGetShaderiv(shader->id, GL_COMPILE_STATUS, &isComplite);

		std::cout << "[OpenGL][Debug][Shader] >> "
			<< "SHADER: " << ShaderCompiler::shaderType(shader->type)
			<< " | COMPILATION: ";

		if (isComplite == GL_FALSE) {
			GLint errorLength = 0;
			glGetShaderiv(shader->id, GL_INFO_LOG_LENGTH, &errorLength);

			std::vector<GLchar> errorLog(errorLength);
			glGetShaderInfoLog(shader->id, errorLength, &errorLength, &errorLog[0]);

			std::string errorMesage(errorLog.begin(), errorLog.end());

			std::cout << "FAIL | MESSAGE: " << errorMesage << std::endl;
			return;
		}
		std::cout << "SUCCESS" << std::endl;
	}

}
