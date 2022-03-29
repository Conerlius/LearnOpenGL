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
	// 通过shader名称获取gpu上的shader程序对象
	GLuint GetShader(std::string name);
	// 编译shader
	void CompileShader(const char* vertex_path, const char* fragment_path, std::string name);
	// 使用shader
	GLuint UseShader(std::string name);

	// 加载图片资源
	GLuint LoadTexture(const char* path);

	static OpenGL_Tools* GetInstance();
};