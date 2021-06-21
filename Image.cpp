#include "Image.h"
#include "stb_image.h"

Image::Image(const std::string& path):path(path), buffer(nullptr), width(0), height(0), bitPerPixel(0)
{
	stbi_set_flip_vertically_on_load(1);
	buffer = stbi_load(path.c_str(), &width, &height, &bitPerPixel, 4);
}

int Image::getWidth()
{
	return width;
}

int Image::getHeight()
{
	return height;
}

unsigned char* Image::getBuffer()
{
	return buffer;
}

Image::~Image()
{
	stbi_image_free(buffer);
}
