#include "PixelR.h"
unsigned int  Shader::CreateShader(std::string pathto_vertexshader, std::string pathto_fragmentshader)
{
	int success; char info[512];
	std::string v_shader_data=Utility::ReadFile(pathto_vertexshader);
	std::string f_shader_data = Utility::ReadFile(pathto_fragmentshader);
	const char* vertexshaderdata = v_shader_data.c_str();
	const char* fragmentshaderdata = f_shader_data.c_str();
	unsigned int vertexshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexshader, 1, &vertexshaderdata, NULL);
	glCompileShader(vertexshader);
	glGetShaderiv(vertexshader,GL_COMPILE_STATUS,&success);
	if (!success)
	{
		glGetShaderInfoLog(vertexshader, 512, NULL, info);
		std::cout << "failed" << info << std::endl;
	}
	unsigned int fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentshader, 1, &fragmentshaderdata, NULL);
	glCompileShader(fragmentshader);
	glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentshader, 512, NULL, info);
		std::cout << "failed" << info << std::endl;
	}
	unsigned int shaderid=glCreateProgram();
	glAttachShader(shaderid, vertexshader);
	glAttachShader(shaderid, fragmentshader);
	glLinkProgram(shaderid);
	glDeleteShader(vertexshader);
	glDeleteShader(fragmentshader);
	return shaderid;
}