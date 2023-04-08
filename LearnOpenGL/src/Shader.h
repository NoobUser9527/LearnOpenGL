#pragma once
#include <string>
#include <glm/glm.hpp>

#include <glad/glad.h>

#include <fstream>
#include <sstream>
#include <iostream>
class Shader
{
public:
	unsigned int ID;
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();
	void Bind();
	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
	void SetFloat4(const std::string& name, float x, float y, float z,float w);
	void SetVec2(const std::string& name, glm::vec2& value);
	void SetVec2(const std::string& name, float x, float y);
	void SetVec3(const std::string& name, glm::vec3& value);
	void SetVec3(const std::string& name, float x, float y, float z);
	void SetVec4(const std::string& name, glm::vec4& value);
	void SetVec4(const std::string& name, float x, float y, float z, float w);
	void SetMat2(const std::string& name, const glm::mat2& matrix);
	void SetMat3(const std::string& name, const glm::mat3& matrix);
	void SetMat4(const std::string& name, const glm::mat4& matrix);
private:
	void CheckCompileErrors(unsigned int shader, std::string type);
};

