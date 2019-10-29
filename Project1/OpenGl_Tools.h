#pragma once
#include <glad/glad.h>
#include <iostream>
#include <map>

class OpenGl_Tools {
private:
	static std::map<const char*, GLuint> shader_map;
public:
	OpenGl_Tools();
	~OpenGl_Tools();
	// 通过shader名称获取gpu上的shader程序对象
	static GLuint GetShader(const char* name);
	// 编译shader
	static void CompileShader(const char* vertex_path, const char* fragment_path, const char* name);
};