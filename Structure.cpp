#include "Structure.h"

Structure::Structure(): buffers(){}

void Structure::addElement(std::string name)
{
	//this->buffers.insert(std::map<std::string, Buffer>::value_type(name, Buffer(ARRAY)));
	//this->buffers.emplace(std::make_pair(name, Buffer(ARRAY)));
	this->buffers.emplace(name, Buffer(ARRAY));
}

Buffer& Structure::getBuffer(std::string name)
{
	auto pair = buffers.find(name);
	if(pair != buffers.end())
		return pair->second;
}

void Structure::bind()
{
	for (auto& const buffer : buffers) {
		buffer.second.bind();
	}
}

std::vector<std::string> Structure::getNames()
{
	std::vector<std::string> names;
	for (auto& const buffer : buffers) {
		names.push_back(buffer.first);
	}
	return names;
}
