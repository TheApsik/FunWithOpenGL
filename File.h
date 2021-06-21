#pragma once
#include <string>
#include <fstream>

class File
{
private:
	std::string data;
	std::string path;

	void readFile();

public:

	File(std::string path);

	std::string getData();

};

