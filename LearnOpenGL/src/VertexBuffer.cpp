#include "VertexBuffer.h"



VertexBuffer::VertexBuffer(const void* data)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}


VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &ID);
}

void VertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VertexBuffer::AddAttrib(unsigned int count, unsigned int type)
{
	Bind();
	
	glVertexAttribPointer(location, count, type, GL_FALSE, stride, (void*)pointer);
	
	location++;
	pointer += count * GetSizeOfType(type);

}
void VertexBuffer::AddAttrib(unsigned int count)
{
	Bind();

	glVertexAttribPointer(location, count, GL_FLOAT, GL_FALSE, stride, (void*)pointer);

	location++;
	pointer += count * sizeof(float);

}