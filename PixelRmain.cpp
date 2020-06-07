#include "PixelR.h"

int main()
{
	PixelWindow pixelGamewindow;//init window
	pixelGamewindow.init_GameWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE.c_str());//<--init
	glfwSetFramebufferSizeCallback(pixelGamewindow.GameWindow,OnWindowResize);//sets window resize cb
	Shapes rect;
	rect.Rect2D();
	unsigned int testshader = Shader::CreateShader("C:\\PixelRenderer\\Shaders\\defaultvertexshader.txt", "C:\\PixelRenderer\\Shaders\\defaultfragmentshader.txt");
	unsigned int texturetest = Texture2D::loadtexture("C:\\PixelRenderer\\res\\images.jpg");
	//game loop
	while (!glfwWindowShouldClose(pixelGamewindow.GameWindow))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glBindTexture(GL_TEXTURE_2D, texturetest);
		glUseProgram(testshader);
		
		glBindVertexArray(rect.VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glfwSwapBuffers(pixelGamewindow.GameWindow);
		glfwPollEvents();
	}
	
	return 0;
}
void OnWindowResize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}