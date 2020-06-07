#pragma once
#include <iostream>
#include <string>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "stb_image.h"
#include <fstream>
const unsigned int SCREEN_WIDTH = 600;
const unsigned int SCREEN_HEIGHT= 600;
const std::string TITLE="PixelHeros";
void OnWindowResize(GLFWwindow* window, int width, int height);//impliment this and assing to framzebuffersizechangecallback
class PixelWindow
{
public:
	GLFWwindow* GameWindow=NULL;
	bool init_GameWindow(int width,int heigh,std::string title);
};
struct Pvector3f
{
	float x; float y; float z;
};
class Shapes
{
	
	public:
	unsigned int VBO, VAO;
	void Rect2D();
};
static class Utility
{
public:
	static std::string ReadFile(std::string pathtofile);
};
static class Shader
{
public:
	unsigned static int CreateShader(std::string pathto_vertexshader, std::string pathto_fragmentshader);
};
static class Texture2D
{
	void load();
};

