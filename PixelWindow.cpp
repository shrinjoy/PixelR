#include "PixelR.h"
bool PixelWindow::init_GameWindow(int width, int height, std::string title)
{
	glfwInit();//inits glfw
	GameWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);//creates window
	//if window creation fails return false
	if (!GameWindow)
	{
		std::cout << "FAILED TO CREATE WINDOW" << std::endl;
		return false;
	}
	glfwMakeContextCurrent(GameWindow);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "FAILED LOADING openGL" << std::endl;
		return false;
	}
	glViewport(0, 0, width, height);
	return true;
}
