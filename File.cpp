#include "File.h"

void File::readFile()
{
	std::ifstream fileRead(path);
	std::string line;
	while (std::getline(fileRead, line))
	{
		data += line + '\n';
	}

	fileRead.close();
}

File::File(std::string path):path(path)
{
	readFile();
}

std::string File::getData()
{
	return data;
}
