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
	// 通过shader名称获取gpu上的shader程序对象
	GLuint GetShader(std::string name);
	// 编译shader
	void CompileShader(const char* vertex_path, const char* fragment_path, std::string name);
	// 使用shader
	void UseShader(std::string name);

	static OpenGL_Tools* GetInstance();
};