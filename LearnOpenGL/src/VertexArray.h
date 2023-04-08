#pragma once
#include <glad/glad.h>
#include "VertexBuffer.h"
class VertexArray
{
public:
	unsigned int ID;
	VertexArray();
	~VertexArray();
	void Bind();
	void AddBuffer(VertexBuffer vb);
};

