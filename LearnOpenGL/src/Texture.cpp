#include "Texture.h"

Texture::Texture(const char* path)
{
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	// 翻转Texture
	stbi_set_flip_vertically_on_load(true);
	
	unsigned char* pixels = stbi_load(path, &width, &height, &nrChannels, 4);
	// req_comp
	// 1 灰度图
	// 2 灰度图加透明度
	// 3 红绿蓝 RGB 三色图
	// 4 红绿蓝加透明度 RGBA 图

	if (pixels)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels); \
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "加载纹理:\"" << path << "\"失败！" << std::endl;
	}
	stbi_image_free(pixels);
}

Texture::~Texture()
{
	glDeleteTextures(1, &ID);
}

void Texture::Bind(unsigned int slot /* = 0 */)
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, ID);
}


