#pragma once
#include "Shader.h"
#include <iostream>
#include <vector>
#include "OpenGL.h"
class ShaderCompiler
{
private:
	ShaderCompiler();
public:
	static std::string shaderType(ShaderType type);
	static bool debugMode;
	static void compile(Shader* shader);
};

