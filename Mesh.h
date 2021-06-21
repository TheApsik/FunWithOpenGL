#pragma once
#include <vector>
#include <GL/glew.h>
#include "Vector3.h"
#include "Buffer.h"
#include "Attribute.h"
#include "Structure.h"
#include "OpenGL.h"
#include "Drawable.h"
#include "VertexArray.h"
#include <glm/glm.hpp>

class Mesh: public Drawable
{
private:
	std::vector<Vector3> positions;
	std::vector<Vector3> colors;
	std::vector<GLuint> indexes;
	std::vector<glm::vec2> texCoords;

	ShaderProgram* attachedToProgram;

	VertexArray vao;
	Structure structure;
	Buffer index;

public:
	Mesh();

	void Draw(DrawMethod method);
	void BindDrawing(ShaderProgram& program);
	void load();
	void setPositions(std::vector<Vector3> positions);
	void setColors(std::vector<Vector3> colors);
	void setIndexes(std::vector<GLuint> indexes);
	void setTextureCoords(std::vector<glm::vec2> texCoords);
	std::vector<std::string> getListOfVertexAttributes();

	~Mesh();
	
	friend class Object;
	friend class Renderer;
};