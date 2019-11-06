#pragma once
#include <glad/glad.h>
#include <iostream>
#include <map>
#include <string>
//#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

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
	GLuint UseShader(std::string name);

	// ����ͼƬ��Դ
	GLuint LoadTexture(const char* path);

	static OpenGL_Tools* GetInstance();
};