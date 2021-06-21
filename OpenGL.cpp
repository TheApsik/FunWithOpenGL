
#include "OpenGL.h"

void GLAPIENTRY OpenGL::messageCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
										GLsizei length, const GLchar* message, const void* userParam) {
	std::cout << "[OpenGL][Debug][Message] >>"
			  << " TYPE: " << OpenGL::msgType(type)
			  << " | SEVERITY: " << OpenGL::msgSeverity(severity)
			  << " | MESSAGE: " << message
			  << std::endl;
}

std::string OpenGL::msgType(GLenum type)
{
	switch (type) {
	case GL_DEBUG_TYPE_ERROR:
		return "ERROR";
	case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
		return "DEPRECATED_BEHAVIOR";
	case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
		return "_UNDEFINED_BEHAVIOR";
	case GL_DEBUG_TYPE_PORTABILITY:
		return "PORTABILITY";
	case GL_DEBUG_TYPE_PERFORMANCE:
		return "PERFORMANCE";
	case GL_DEBUG_TYPE_MARKER:
		return "MARKER";
	case GL_DEBUG_TYPE_PUSH_GROUP:
		return "PUSH_GROUP";
	case GL_DEBUG_TYPE_POP_GROUP:
		return "POP_GROU";
	case GL_DEBUG_TYPE_OTHER:
		return "OTHER";
	default:
		return "UNKNOWN TYPE 0x" + std::to_string(type); 
	}
}

std::string OpenGL::msgSeverity(GLenum severity)
{
	switch (severity) {
	case GL_DEBUG_SEVERITY_LOW:
		return "LOW";
	case GL_DEBUG_SEVERITY_MEDIUM:
		return "MEDIUM";
	case GL_DEBUG_SEVERITY_HIGH:
		return "HIGH";
	case GL_DEBUG_SEVERITY_NOTIFICATION:
		return "NOTIFICATION";
	default:
		return "UNKNOWN SEVERITY: 0x" + severity;
	}
}

void OpenGL::init(bool debugMode)
{
	glewExperimental = GL_TRUE;
	glewInit();

	if (debugMode) {
		glEnable(GL_DEBUG_OUTPUT);
		glDebugMessageCallback(OpenGL::messageCallback, 0);
	}
}

void OpenGL::errorCheck(const char* file, const int line)
{
	GLenum status;
	while ((status = glGetError()) != GL_NO_ERROR)
	{
		std::cout << "[" << file << ":" << line << "] Error (0x" << std::hex << std::setfill('0') << std::setw(4) << status << ":" << glewGetErrorString(status)
			<< "): "
			// << glewGetErrorString(status)
			<< std::dec << std::endl;
	}
}
