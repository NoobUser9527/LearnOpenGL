#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &ID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &ID);
}

void VertexArray::Bind()
{
	glBindVertexArray(ID);
}

void VertexArray::AddBuffer(VertexBuffer vb)
{
	Bind();
	vb.Bind();
}
