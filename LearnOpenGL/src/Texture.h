#pragma once
#include <stb_image/stb_image.h>

#include <glad/glad.h>
#include <iostream>

class Texture
{
private:

public:
	unsigned int ID;
	unsigned int slot;
	Texture(const char* path);
	~Texture();
	void Bind(unsigned int slot = 0);

};