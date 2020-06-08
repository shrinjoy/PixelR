#pragma once
#include <iostream>
#include <string>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

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
 class Texture2D
{
	 
	public:
		unsigned int textureid;
		int w, h, n;
		void loadtexture(std::string texturepath);
};
class Sprite2D
{
	unsigned int transformloc;
	unsigned int colorloc;
	float x = 0;
	public:
		
		Pvector3f Position = {1.0f,1.0f,0.0f};
		Pvector3f Scale = {1.0f,1.0f,0.0f};
		Pvector3f color={1.0f,1.0f,1.0f};
	void Draw(unsigned int shaderid,float frame_w, float frame_h, float txw, float txh, int row, int col);
};
