#include "PixelR.h"
PIMGUI gui;
void GUI();
int main()
{

	PixelWindow pixelGamewindow;//init gamw window class
	pixelGamewindow.init_GameWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE.c_str());//<--init
	//call gl functions after init game window ^^^^
	glfwSetFramebufferSizeCallback(pixelGamewindow.GameWindow, OnWindowResize);//sets window resize cb
	unsigned int vertfragshader = Shader::CreateShader("C:\\PixelRenderer\\Shaders\\defaultvertexshader.vert", "C:\\PixelRenderer\\Shaders\\defaultfragmentshader.frag");
	Texture2D testtexture;
	testtexture.loadtexture("C:\\PixelRenderer\\res\\male.png");
	Camera2D camera;
	camera.init(vertfragshader, SCREEN_WIDTH, SCREEN_HEIGHT);
	Sprite2D sprite1;
	sprite1.Scale = {0.08,0.08,1 };
	sprite1.Position = { 0,0,0 };
	sprite1.init(vertfragshader);
	sprite1.UpdateRectPosition();
	Shapes rect;
	rect.Rect2D();
	float x = 0.0f;
	

	gui.init(pixelGamewindow.GameWindow);
	
	while (!glfwWindowShouldClose(pixelGamewindow.GameWindow))
	{
		
		x += 1.0f;
		std::this_thread::sleep_for(std::chrono::milliseconds(17));
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glUseProgram(vertfragshader);
		testtexture.usetexture();
		glUseProgram(vertfragshader);	
		glBindVertexArray(rect.VAO);
		sprite1.UpdateSpriteTexture(32, 32, testtexture.w, testtexture.h, x, 1);
		sprite1.Draw();
		GUI();
		glfwSwapBuffers(pixelGamewindow.GameWindow);
		glfwPollEvents();
	}

	return 0;
}
void OnWindowResize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
void GUI()
{
	gui.begin();
	ImGui::Text("test");
	gui.end();
}