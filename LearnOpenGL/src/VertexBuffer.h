#pragma once
#include <glad/glad.h>
#include <iostream>

class VertexBuffer
{
public:
	unsigned int location = 0;
	unsigned int stride = 0;
	unsigned int pointer = 0;
	unsigned int ID;
	VertexBuffer(const void* data);
	~VertexBuffer();

	void Bind();

	void AddAttrib(unsigned int count, unsigned int type);
	void AddAttrib(unsigned int count);
private:
	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT:			return 4;
		case GL_UNSIGNED_INT:	return 4;
		case GL_UNSIGNED_BYTE:	return 1;
		}
		std::cout << "VertexBuffer GetSizeOfType´íÎó!!!" << std::endl;
		return 0;
	}
};

