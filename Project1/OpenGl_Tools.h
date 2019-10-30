#pragma once
#include <glad/glad.h>
#include <iostream>
#include <map>
#include <string>

class OpenGL_Tools {
private:
	std::map<std::string, GLuint> shader_map;
	static OpenGL_Tools* m_pInstance;
public:
	OpenGL_Tools();
	~OpenGL_Tools();
	// ͨ��shader���ƻ�ȡgpu�ϵ�shader�������
	GLuint GetShader(std::string name);
	// ����shader
	void CompileShader(const char* vertex_path, const char* fragment_path, std::string name);
	// ʹ��shader
	void UseShader(std::string name);

	static OpenGL_Tools* GetInstance();
};