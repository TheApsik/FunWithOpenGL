#include "Mesh.h"

void* getRAWBufferData(GLenum bufferType, GLint& size) {
	glGetBufferParameteriv(bufferType, GL_BUFFER_SIZE, &size);
	void* data = new GLbyte[size];

	glGetBufferSubData(bufferType, 0, size, (void*)data);

	return data;
}

void Mesh::Draw(DrawMethod method)
{
	//std::cout << "@";
	glDrawElements(method, indexes.size(), GL_UNSIGNED_INT, nullptr);
	ErrorCheck();
}

void Mesh::BindDrawing(ShaderProgram& program)
{
	vao.bind();
	if (attachedToProgram != &program) {
		attachedToProgram = &program;
		this->index.bind();

		auto namesList = this->structure.getNames();
		for (auto it = namesList.begin(); it != namesList.end(); it++) {
			Buffer& buffer = this->structure.getBuffer(*it);
			buffer.bind();
			program.bindAttribute(*it);
		}
	}
}

Mesh::Mesh():positions(0), colors(0), indexes(0), vao(), index(ELEMENT_ARRAY), structure(), attachedToProgram(nullptr){
	this->structure.addElement("position");
	this->structure.addElement("color");
	this->structure.addElement("texCoord");
}

void Mesh::load()
{
	//Vertex buffers
	vao.bind();
	Buffer& position = this->structure.getBuffer("position");
	position.setData(positions, STATIC_DRAW);
	Buffer& color = this->structure.getBuffer("color");
	color.setData(colors, STATIC_DRAW);
	Buffer& textCoord = this->structure.getBuffer("texCoord");
	textCoord.setData(texCoords, STATIC_DRAW);
	//Index buffer
	this->index.setData(indexes, STATIC_DRAW);
}

void Mesh::setPositions(std::vector<Vector3> positions)
{
	this->positions.assign(positions.begin(), positions.end());
}

void Mesh::setColors(std::vector<Vector3> colors)
{
	this->colors.assign(colors.begin(), colors.end());
}

void Mesh::setIndexes(std::vector<GLuint> indexes)
{
	this->indexes.assign(indexes.begin(), indexes.end());
}

void Mesh::setTextureCoords(std::vector<glm::vec2> texCoords)
{
	this->texCoords.assign(texCoords.begin(), texCoords.end());
}

std::vector<std::string> Mesh::getListOfVertexAttributes()
{
	return structure.getNames();
}

Mesh::~Mesh()
{
	std::cout << "[DESTROY] Mesh\n";
}

