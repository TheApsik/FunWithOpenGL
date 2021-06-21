#pragma once
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <iomanip>

class OpenGL{
private:
	static std::string msgType(GLenum type);
	static std::string msgSeverity(GLenum severity);

    static void GLAPIENTRY messageCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
									GLsizei length, const GLchar* message, const void* userParam);
public:
	static void init(bool debugMode = false);

	static void errorCheck(const char* file, const int line);
};

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define ErrorCheck() OpenGL::errorCheck(__FILENAME__, __LINE__)

