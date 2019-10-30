#pragma once
#include <glad/glad.h>
#include <iostream>
#include <map>
#include <string>

class OpenGl_Tools {
private:
	std::map<std::string, GLuint> shader_map;
	static OpenGl_Tools* m_pInstance;
public:
	OpenGl_Tools();
	~OpenGl_Tools();
	// 通过shader名称获取gpu上的shader程序对象
	GLuint GetShader(std::string name);
	// 编译shader
	void CompileShader(const char* vertex_path, const char* fragment_path, std::string name);

	static OpenGl_Tools* GetInstance()
	{
		if (m_pInstance == NULL)  //判断是否第一次调用
			m_pInstance = new OpenGl_Tools();
		return m_pInstance;
	}

};