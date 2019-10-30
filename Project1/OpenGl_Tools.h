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
	// ͨ��shader���ƻ�ȡgpu�ϵ�shader�������
	GLuint GetShader(std::string name);
	// ����shader
	void CompileShader(const char* vertex_path, const char* fragment_path, std::string name);

	static OpenGl_Tools* GetInstance()
	{
		if (m_pInstance == NULL)  //�ж��Ƿ��һ�ε���
			m_pInstance = new OpenGl_Tools();
		return m_pInstance;
	}

};