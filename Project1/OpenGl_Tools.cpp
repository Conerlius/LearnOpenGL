#include "OpenGL_Tools.h"
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

OpenGL_Tools::OpenGL_Tools()
{
}
OpenGL_Tools::~OpenGL_Tools()
{
}
OpenGL_Tools* OpenGL_Tools::m_pInstance = NULL;

OpenGL_Tools* OpenGL_Tools::GetInstance()
{
	if (m_pInstance == NULL)  //�ж��Ƿ��һ�ε���
		m_pInstance = new OpenGL_Tools();
	return m_pInstance;
}
// ��ȡ�Ѿ������shader
GLuint OpenGL_Tools::GetShader(string name)
{
	map<string, GLuint>::iterator it = shader_map.find(name);
	if (it != shader_map.end()) {
		return it->second;
	}
	else
	{
		return -1;
	}
	return -1;
}

void OpenGL_Tools::UseShader(string name)
{
	GLuint programId = GetShader(name);
	if (programId == -1)
	{
		return;
	}
	glUseProgram(programId);
}
// ����shader
// vertex_path	vertex�ļ�·��
// fragment_path	fragment�ļ�·��
// name		shader����
void OpenGL_Tools::CompileShader(const char* vertex_path, const char* fragment_path, string name)
{
	if (GetShader(name) != -1)
		return;
	// ����Vertex��Fragment�Ķ���id
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	// ��Vertex�ı�
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream (vertex_path, std::ios::in);
	if (VertexShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << VertexShaderStream.rdbuf();
		VertexShaderCode = sstr.str();
		VertexShaderStream.close();
	}
	else {
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_path);
		getchar();
		return ;
	}
	// ��Fragment�ı�
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragment_path, std::ios::in);
	if (FragmentShaderStream.is_open()) {
		std::stringstream sstr;
		sstr << FragmentShaderStream.rdbuf();
		FragmentShaderCode = sstr.str();
		FragmentShaderStream.close();
	}
	else {
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", fragment_path);
		getchar();
		return ;
	}
	// ��ʼ����
	GLint Result = GL_FALSE;
	int InfoLogLength;
	// Compile Vertex Shader
	printf("Compiling shader : %s\n", vertex_path);
	char const* VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
	glCompileShader(VertexShaderID);

	// ���Vertex�������
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}
	// Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_path);
	char const* FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
	glCompileShader(FragmentShaderID);

	// ���Fragment�������
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}

	// Link the program
	printf("Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// ��� shader program�����
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}

	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);
	// ��¼
	shader_map.insert(std::pair<string, GLuint>(name, ProgramID));
}