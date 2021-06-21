#pragma once
#include "Attribute.h"
#include "Buffer.h"
#include <vector>
#include <map>
class Structure
{
	std::map<std::string, Buffer> buffers;
public:
	Structure();
	void addElement(std::string name);
	Buffer& getBuffer(std::string name);
	void bind();
	std::vector<std::string> getNames();
};

