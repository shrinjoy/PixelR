//this is the main header for the pixel rendere 2d 
//i started this project because i wanted to play around with opengl3 
//dont expect too much from it
//this renderer is very barebone
//a super simple 2d renderer using glfw and glad aka 2d over opengl
//features:
/*
window creation 
camera2d
glsl shader support
texture loading
sprite
sprite animation
*/
//pixelR requres user to create their own opengl loop and handle clear screen and update loop optimization
//pixelR also requres u to handle the alpha blending using glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);glEnable(GL_BLEND);
//and glDisable(GL_CULL_FACE);
//this is a very simple layer over opengl and you will have to do many things manually 
//todo
//sprite batching <--optimization tho i belive this optimization is not really needed but i will add it 
#pragma once
#define GLFW_INCLUDE_NONE 
#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#include <iostream>
#include <string>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/random.hpp>
#include <chrono>
#include <thread>
#include <fstream>
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"
const unsigned int SCREEN_WIDTH = 900;
const unsigned int SCREEN_HEIGHT = 900;
const std::string TITLE = "PixelHeros";
void OnWindowResize(GLFWwindow* window, int width, int height);//impliment this and assing to framzebuffersizechangecallback
class PixelWindow
{
public:
	GLFWwindow* GameWindow = NULL;
	bool init_GameWindow(int width, int heigh, std::string title);
	
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
class Camera2D
{
	//type 1 = projection 0 = orthographic
	glm::mat4 projection;
	glm::mat4 view;
	unsigned int projection_shader_location;
	unsigned int view_shader_location;
	unsigned int enablecamera;
public:
	glm::vec3 camera_position = { 0,0,0.0f };
	float camera_near_clip = 0.1f;
	float camera_far_clip = 100.0f;
	void init(unsigned int shaderid, float screen_width, float screen_height, float fov = 45.0f);
	void Update();
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
	void usetexture();
};
class Sprite2D
{
	unsigned int transformloc;//shader transform variable location mat4 need for scaleing and moving sprite arnd
	unsigned int colorloc;//shader color variable location vec3 need for color
	unsigned int txlocc;//shader texture offset mat4 location need for sprite animation
	glm::mat4 txtran=glm::mat4(1.0f);
	glm::mat4 trans=glm::mat4(1.0f);
public:
	//default values
	bool dataupdated = true;
	Pvector3f Position = { 1.0f,1.0f,0.0f };
	Pvector3f Scale = { 1.0f,1.0f,0.0f };
	Pvector3f color = { 1.0f,1.0f,1.0f };
	void init(unsigned int shaderid);
	void UpdateSpriteTexture(float frame_w, float frame_h, float txw, float txh, int col, int row);
	void UpdateRectPosition();
	void Draw();//draws shit
};
class PIMGUI
{
	
public:
	void init(GLFWwindow* window);
	void begin();
	void end();

};
