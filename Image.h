#pragma once
#include <string>
class Image
{
private:
	std::string path;
	unsigned char* buffer;
	int width;
	int height;
	int bitPerPixel;

public:
	Image(const std::string& path);

	int getWidth();
	int getHeight();
	unsigned char* getBuffer();

	~Image();
};

